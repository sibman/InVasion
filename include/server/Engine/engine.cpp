#include "engine.h"
// interactors
#include "interactors/MoveInteractor/move-interactor.h"
#include "interactors/UpdateGameStateInteractor/update-game-state-interactor.h"
#include "interactors/ShootInteractor/shoot-interactor.h"
// request-models
#include "move-request-model.pb.h"
#include "shoot-request-model.pb.h"
#include "player.pb.h"
// response-models
#include "player-position-response-model.pb.h"
#include "players-positions-response-model.pb.h"


namespace invasion::session {

void manageRequestQueue(SafeQueue<NetworkPacketRequest> &requestQueue, SafeQueue<NetworkPacketResponse> &responseQueue, game_models::GameSession &gameSession) {
    std::thread([requestQueue = &requestQueue, responseQueue = &responseQueue, gameSession = &gameSession]() {
        while (true) {
            NetworkPacketRequest request;
            if (requestQueue->consumeSync(request)) {
                // work with this object
                switch (request.getMessageType()) {
                    case RequestModel_t::UpdateGameStateRequestModel: {
                        interactors::UpdateGameStateInteractor interactor;
                        response_models::PlayersPositionsResponseModel responseModel = interactor.execute(*gameSession);

                        // serialize
                        std::unique_ptr<char[]> buffer_ptr(new char[responseModel.ByteSizeLong()]);
                        responseModel.SerializeToArray(buffer_ptr.get(), responseModel.ByteSizeLong());
                        
                        NetworkPacketResponse response(std::move(buffer_ptr),
                                                        ResponseModel_t::PlayersPositionsResponseModel,
                                                        responseModel.ByteSizeLong());
                        
                        responseQueue->produce(std::move(response));
                        break;
                    }
                    case RequestModel_t::MoveRequestModel: {
                        request_models::MoveRequestModel move;
                        move.ParseFromArray(request.getStoredBytes(), request.bytesSize());
                        interactors::MoveInteractor interactor;
                        interactor.execute(move, *gameSession);
                        break;
                    }
                    case RequestModel_t::PlayerActionRequestModel: { //  leave it for now, then we will delete this request/response-model
                        PlayerAction action; // buttons
                        action.ParseFromArray(request.getStoredBytes(), request.bytesSize());

                        std::cout << "Action button: " << action.key_pressed() << std::endl;
                        std::unique_ptr<char[]> bytes_ptr = request.getPureBytes();
                        NetworkPacketResponse response(std::move(bytes_ptr), ResponseModel_t::PlayerActionResponseModel, request.bytesSize());
                        
                        responseQueue->produce(std::move(response));
                        break;
                    }
                    case RequestModel_t::ShootRequestModel: {
                        request_models::ShootRequestModel shootAction;
                        shootAction.ParseFromArray(request.getStoredBytes(), request.bytesSize());

                        interactors::ShootInteractor interactor;
                        response_models::ShootingStateResponse responseModel = interactor.execute(shootAction, *gameSession);
                        
                        // serialize
                        std::unique_ptr<char[]> buffer_ptr(new char[responseModel.ByteSizeLong()]);
                        responseModel.SerializeToArray(buffer_ptr.get(), responseModel.ByteSizeLong());

                        NetworkPacketResponse response(std::move(buffer_ptr),
                                                        ResponseModel_t::ShootingStateResponseModel,
                                                        responseModel.ByteSizeLong());
                        
                        responseQueue->produce(std::move(response));
                        // std::shared_ptr<Client> client = server->getConnectedClientByPlayerId(responseModel.player_id());
                        // if (client) {
                        //     client->m_clientResponseQueue.produce(std::move(response));
                        // }

                        break;
                    }
                    // case
                    default: {
                        std::cout << "Unknown message type: " << static_cast<int> (request.getMessageType())
                                    << std::endl;
                        break;
                    }
                }
            }
        }
    }).detach();
}

}
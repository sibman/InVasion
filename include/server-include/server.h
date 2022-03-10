
#ifndef INVASION_SERVER_SERVER_H
#define INVASION_SERVER_SERVER_H

#include "../../include/server-include/safe-queue.h"
#include "player.pb.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <utility>
#include "user.h"
#include "receiver.h"
#include "sender.h"
#include "engine.h"
#include "request-response.h"
using boost::asio::ip::tcp;
namespace inVasion::session {
    inline std::vector<std::shared_ptr<User>> baseUsers;

    inline void dispatcherEachSender(SafeQueue<ResponseObject> *queueClientsFromServer) {
        while (true) {
            ResponseObject cur;
            if (queueClientsFromServer->consumeSync(cur)) {
                for (auto cur_client: baseUsers) { // пока никакой обработки просто имитируем ее
                    ResponseObject tmp = cur;
                    cur_client->queueToClientPrivate.produce(std::move(tmp));
                }
            }
        }
    }

    class Server {
    private:
        boost::asio::io_context ioContext;
        tcp::acceptor acceptor;
        const size_t NUMBER_OF_TEAM = 1;
        bool ImplementedDispatherEachSender = false;
        SafeQueue<RequestObject> queueServerFromClients;
        SafeQueue<ResponseObject> queueClientsFromServer;
    public:

        explicit Server();

        void makeSenderUsers();

        void waitNewUser();

        friend void makeEngine(SafeQueue<RequestObject> &queueServerFromClients, SafeQueue<ResponseObject> &queueClientsFromServer);

        friend class ReceiverFromUser;

        friend void dispatcherEachSender(SafeQueue<ResponseObject> *queueClientsFromServer);
    };

}
#endif //INVASION_SERVER_SERVER_H

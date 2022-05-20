#include <iostream>
#include <vector>

#include "game-models/Vector2D/vector2d.h"
#include "game-models/Player/player.h"
#include "game-models/GameWorldManager/game-world-manager.h"

#include "interactors/MoveInteractor/move-interactor.h"

#include "doctest.h"


namespace doctest {


TEST_CASE("creating physics") {
	using namespace invasion::game_models;
	using namespace invasion::interactors;
	using namespace std;

	int totalSimulationTime = 40;
    int currentTime = 0;
    int dt = 1;

	MoveInteractor interactor;
	GameWorldManager manager;
	MoveRequestModel req(MoveRequestModel::MoveEvent::StartMovingUp);
	
	vector<Player> players = { 
		Player(Vector2D::ZERO)
	};

	// start moving
	interactor.execute(req, players[0]);

	while(currentTime < totalSimulationTime) {
		cout << "time: " << currentTime << " velocity: " << players[0].getVelocity() << endl;

		// stop event
		if(currentTime == 10) {
			std::cout << "start stopping..." << std::endl;
			req.setEvent(MoveRequestModel::MoveEvent::StopMovingUp);
			interactor.execute(req, players[0]);
		}

		manager.updatePlayersPositions(players, dt);

		currentTime += dt;
	}

	cout << "time: " << currentTime << " velocity: " << players[0].getVelocity() << endl;
}


} // namespace doctest
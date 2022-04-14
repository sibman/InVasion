#ifndef GAME_WORLD_MANAGER_H_
#define GAME_WORLD_MANAGER_H_

#include <vector>

#include "game-models/Player/player.h"
#include "game-models/Vector2D/vector2d.h"
#include "game-models/KinematicObject/kinematic-object.h"


namespace invasion::game_models {
	

struct GameWorldManager {
	void updatePlayersPositions(std::vector<Player>& players, double dt) const;

private:
	void applyFrictionAndSetResultForceOnPlayer(Player& player, double dt) const;
	
	void updateResultForceAndVelocityOfPlayerOnCollisionsWithOtherPlayers(
		std::vector<Player>& players, 
		Player& consideredPlayer, 
		double dt
	) const;
};


} // namespace invasion::game_models

#endif // GAME_WORLD_MANAGER_H_

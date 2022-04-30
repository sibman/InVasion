#ifndef PLAYER_MANAGER_H_
#define PLAYER_MANAGER_H_

#include <vector>
#include <memory>
// game-models
#include "game-models/Player/player.h"


namespace invasion::game_models {
	
class PlayerManager {
public:
	void updatePlayersPositions(std::vector<std::shared_ptr<Player>>& players, double dt) const;

	void findDamagedPlayers(std::vector<std::shared_ptr<Player>>& players,
							std::vector<std::shared_ptr<Player>>& damagedPlayers) const;

private:
	void applyFrictionAndSetResultForceOnPlayer(std::shared_ptr<Player> player_ptr, double dt) const;
	
	void updatePlayerPhysicsOnPlayerCollision(std::vector<std::shared_ptr<Player>>& players,
											  std::shared_ptr<Player> consideredPlayer_ptr,
											  double dt) const;
};

} // namespace invasion::game_models



#endif // PLAYER_MANAGER_H_

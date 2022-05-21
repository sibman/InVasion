#include <memory>
#include <algorithm>

#include "aid-kit.h"

// game-models
#include "game-models/StaticSupply/static-supply.h"
#include "game-models/StaticSupply/static-supply-enum.h"
#include "game-models/Player/player.h"
#include "game-models/Player/player-life-state.h"
#include "game-models/Vector2D/vector2d.h"


namespace invasion::game_models {
	
AidKit::AidKit(Vector2D initialPosition,
				int supplyId,
				int playerId)
	: StaticSupply(
		AidKit::SHAPE_COLLIDER_SIZE,
		initialPosition,
		supplyId,
		StaticSupplyType::AidKit,
		playerId,
		AidKit::INITIAL_SUPPLY_CAPACITY
	) {}


void AidKit::supply(std::shared_ptr<Player> player) {
	PlayerLifeState lifeState = player->getLifeState();

	const int initialHitPoints = lifeState.getInitialHitPoints();
	const int currentHitPoints = lifeState.getHitPoints();

	int addon = std::max(initialHitPoints - currentHitPoints, AidKit::SUPPLY_PORTION);

	if(addon >= m_leftSupplyCapacity) {
		addon = m_leftSupplyCapacity;
		m_leftSupplyCapacity = 0;
		m_isActive = false;
	}
	else {
		m_leftSupplyCapacity -= addon;
	}

	lifeState.applyHealing(addon);
}

} // namespace invasion::game_models

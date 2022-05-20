#ifndef KINEMATIC_OBJECT_H_
#define KINEMATIC_OBJECT_H_


#include "game-models/Vector2D/vector2d.h"
#include "game-models/Object/object.h"



namespace invasion::game_models {

struct KinematicObject : Object {

	explicit KinematicObject(Vector2D collider_size, Vector2D initial_pos, double mass, double max_speed);

	Vector2D getVelocity() const;
	void setVelocity(Vector2D velocity);

	Vector2D getMovingForce() const;
	void setMovingForce(Vector2D force);

	Vector2D getResultForce() const;
	void setResultForce(Vector2D force);

	Vector2D getAcceleration() const;

	Vector2D intentMove(double dt) const;
	void makeMove(double dt);

	void setMovingState(bool state);
	bool isMoving() const;

protected:
	Vector2D m_velocity;
	Vector2D m_acceleration;
	Vector2D m_moving_force;
	Vector2D m_result_force;
	const double m_mass;
	const double m_max_speed;
	bool m_moving;
};


} // namespace invasion::game_models



#endif // KINEMATIC_OBJECT_H_
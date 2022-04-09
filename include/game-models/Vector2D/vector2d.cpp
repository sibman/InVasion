#include <iostream>
#include <cassert>
#include <cmath>

#include "vector2d.h"


namespace invasion::game_models {
const Vector2D Vector2D::ZERO = Vector2D(0.0, 0.0);
const double Vector2D::EPS = 1e-8;

Vector2D::Vector2D(double x, double y)
	: m_x(x), m_y(y) {}


void Vector2D::setX(double x) {
	m_x = x;
}


double Vector2D::getX() const {
	return m_x;
}


void Vector2D::setY(double y) {
	m_y = y;
}


double Vector2D::getY() const {
	return m_y;
}

double Vector2D::magnitude() const {
	return std::sqrt(m_x * m_x + m_y * m_y);
}

Vector2D Vector2D::normalize() const {
	const double magnitude = std::sqrt(m_x * m_x + m_y * m_y);
	
	if(magnitude < Vector2D::EPS) {
		return Vector2D::ZERO;
	}
	
	return *this / magnitude;
}

// static
Vector2D Vector2D::clampMagnitude(const Vector2D& vec, const double magnitude) {
	return vec.normalize() * magnitude;
}


// operators
Vector2D Vector2D::operator+(const Vector2D& other) const {
	return Vector2D(m_x + other.m_x, m_y + other.m_y);
}

Vector2D& Vector2D::operator+=(const Vector2D& other) {
	m_x += other.m_x;
	m_y += other.m_y;
	return *this;
}

Vector2D operator*(const Vector2D& vec, double value) {
	return Vector2D(vec.m_x * value, vec.m_y * value);
}

Vector2D operator*(double value, const Vector2D& vec) {
	return Vector2D(vec.m_x * value, vec.m_y * value);
}

Vector2D operator/(const Vector2D& vec, double value) {
	assert(std::abs(value) > Vector2D::EPS);
	return Vector2D(vec.m_x / value, vec.m_y / value);
}

std::ostream& operator<<(std::ostream& os, const Vector2D& vec) {
	os << "Vector2D (" << vec.m_x << ", " << vec.m_y << ")";
	return os;
}

} // namespace invasion::game_models

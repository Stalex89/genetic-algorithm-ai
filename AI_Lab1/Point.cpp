#include "stdafx.h"
#include "Point.h"

// Generates random positive or negative point
Point::Point(bool isPositive)
{
	if (isPositive)
		m_x = getRandomNumber(-10.0, -1.0);
	else
		m_x = getRandomNumber(1.0, 10.0);
	m_y = getRandomNumber(0.0, 10.0);
}

Point::Point(double x, double y) : m_x(x), m_y(y) {}
void Point::setX(double x) { m_x = x; }
void Point::setY(double y) { m_y = y; }
double Point::getX() { return m_x; }
double Point::getY() { return m_y; }
void Point::printPoint() { std::cout << "(" << m_x << ", " << m_y << ")"; }
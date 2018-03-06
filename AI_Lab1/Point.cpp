#include "stdafx.h"
#include "Point.h"

// Generates random positive or negative point
Point::Point(bool isPositive, double minX, double maxX, double minY, double maxY)
{
	if (isPositive)
		m_x = getRandomNumber(minX, -1.0);
	else
		m_x = getRandomNumber(1.0, maxX);
	m_y = getRandomNumber(minY, maxY);
}

Point::Point(double x, double y) : m_x(x), m_y(y) {}
void Point::setX(double x) { m_x = x; }
void Point::setY(double y) { m_y = y; }
double Point::getX() { return m_x; }
double Point::getY() { return m_y; }
void Point::printPoint() { std::cout << "(" << m_x << ", " << m_y << ")"; }
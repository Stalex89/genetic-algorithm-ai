#include "stdafx.h"
#include "Point.h"
#include "PointSet.h"

PointSet::PointSet(int pointNum, bool isPositive, double minX, double maxX, double minY, double maxY) : m_isPositive(isPositive)
{
	m_pointSet = new std::vector<Point>();
	
	for(int i = 0; i < pointNum; i++)
		m_pointSet->push_back(Point(isPositive, minX, maxX, minY, maxY));
}

void PointSet::printSet()
{
	for (unsigned int i = 0; i < m_pointSet->size(); i++)
	{
		m_pointSet->at(i).printPoint();
	}

}

int PointSet::getPointsetSize()
{
	return m_pointSet->size();
}

Point PointSet::getPointAt(unsigned int idx)
{
	return m_pointSet->at(idx);
}

std::vector<Point> PointSet::getPoints()
{
	std::vector<Point> points;
	for (unsigned int i = 0; i < m_pointSet->size(); i++)
		points.push_back(m_pointSet->at(i));
	return points;
}

PointSet::~PointSet()
{
	delete m_pointSet;
	m_pointSet = nullptr;
}
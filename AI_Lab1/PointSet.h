#pragma once
#include "stdafx.h"
#include <vector>


// A PointSet class represents a positive or negative set of points
class PointSet
{
	std::vector<Point> *m_pointSet;
	bool m_isPositive;

public:
	PointSet(int pointNum, bool isPositive, double minX, double maxX, double minY, double maxY);
	std::vector<Point> getPoints();
	Point getPoint(unsigned int idx);
	int getPointsetSize();
	void printSet();
	~PointSet();
};




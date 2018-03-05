#pragma once
#include "stdafx.h"
#include <vector>


// A PointSet class represents a positive or negative set of points
class PointSet
{
	std::vector<Point> *m_pointSet;
	bool m_isPositive;

public:
	PointSet(int pointNum, bool isPositive);
	std::vector<Point> getPoints();
	~PointSet();
	int getPointsetSize();
	Point getPoint(unsigned int idx);
	void printSet();
};




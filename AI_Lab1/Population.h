#pragma once
#include "stdafx.h"
#include "Curve.h"
#include <vector>

class Population
{
	int m_populationSize;
	static int m_generationNum;
	std::vector<Curve*> *m_populationSet;


public:
	Population(int populationSize, int degree, int minCoefficient, int maxCoefficient);
	Population(std::vector<Curve*> *generationSet);
	//Population(int populationSize, int degree, std::vector<Curve> &populationSet);
	int getPopulationSize();
	Curve* getCurveAt(int idx);
	int getGenerationNum();
	void printPopulation();
	~Population();
};


#pragma once
#include "stdafx.h"
#include "Coefficient.h"
#include <vector>

class Curve
{
	std::vector<Coefficient*> *m_coefficients;
	int m_degree;
	double m_fitness;

public:
	Curve(int degree, int minCoefficient, int maxCoefficient);
	Curve(std::vector<Coefficient*> *coefficients);
	int getDegree();
	Coefficient *getCoefficientAt(unsigned int idx);
	std::vector<int> getDecimalCoefficients();
	double getFitness();
	void setFitness(double fitness);
	void printCoefficients();
	~Curve();
};


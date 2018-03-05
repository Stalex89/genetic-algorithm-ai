#include "stdafx.h"
#include "Curve.h"
#include "Coefficient.h"
#include <exception>

// Generate a curve of n degree with random coefficients 
Curve::Curve(int degree) : m_degree(degree)
{
	m_fitness = 0;
	m_coefficients = new std::vector<Coefficient*>();
	for (int i = 0; i < degree+1; i++)
	{
		m_coefficients->push_back(new Coefficient());
	}
}

Curve::Curve(std::vector<Coefficient*> *coefficients)
{
	m_degree = coefficients->size() - 1;
	m_fitness = 0;
	m_coefficients = coefficients;
}

int Curve::getDegree()
{
	return m_degree;
}

double Curve::getFitness()
{
	return m_fitness;
}

void Curve::setFitness(double fitness)
{
	m_fitness = fitness;
}

Coefficient *Curve::getCoefficientAt(unsigned int idx)
{
	return m_coefficients->at(idx);
}

std::vector<int> Curve::getDecimalCoefficients()
{
	std::vector<int> decimalCoef;

	for (unsigned int i = 0; i < m_coefficients->size(); i++)
	{
		decimalCoef.push_back(m_coefficients->at(i)->getNumber());
	}
	return decimalCoef;
}

void Curve::printCoefficients()
{
	for (unsigned int i = 0; i < m_coefficients->size(); i++)
	{
		m_coefficients->at(i)->printBinary();
		std::cout << '\n';
	}
}

Curve::~Curve()
{
	delete m_coefficients;
	m_coefficients = nullptr;
}

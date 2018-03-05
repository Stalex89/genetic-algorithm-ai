#include "stdafx.h"
#include "Population.h"


Population::Population(int populationSize, int degree, int minCoefficient, int maxCoefficient) : m_populationSize(populationSize)
{
	m_generationNum++;
	m_populationSet = new std::vector<Curve*>();
	for (int i = 0; i < m_populationSize; i++)
		m_populationSet->push_back(new Curve(degree, minCoefficient, maxCoefficient));
}

Population::Population(std::vector<Curve*> *generationSet)
{
	m_populationSize = generationSet->size();
	m_generationNum++;
	m_populationSet = generationSet;
}

int Population::getPopulationSize()
{
	return m_populationSize;
}

int Population::getGenerationNum()
{
	return m_generationNum;
}

void Population::printPopulation()
{
	for (unsigned int i = 0; i < m_populationSet->size(); i++)
	{
		std::cout << "individual = " << i+1 << '\n';
		m_populationSet->at(i)->printCoefficients();
		std::cout << '\n';
	}
}

Curve* Population::getCurveAt(int idx)
{
	return m_populationSet->at(idx);
}

int Population::m_generationNum = 0;

Population::~Population()
{
	delete m_populationSet;
	m_populationSet = nullptr;
}

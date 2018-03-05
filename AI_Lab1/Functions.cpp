#pragma once
#include "stdafx.h"
#include <cmath>
#include <vector>
#include <deque>
#include "Functions.h"
#include "RandomNumberGenerator.h"

bool isPointPositiveSecondDegree(double x, double y, Curve &curve);
bool isPointPositiveThirdDegree(double x, double y, Curve &curve);
bool isPointPositiveFourthDegree(double x, double y, Curve &curve);
bool isPointPositiveFifthDegree(double x, double y, Curve &curve);

double calculateFitness(Curve &curve, PointSet &positiveSet, PointSet &negativeSet)
{
	int fitnessScore = 0;

	// function pointer for selecting curve function based on degree of polynomial
	bool(*fcnPtr)(double x, double y, Curve &curve) = nullptr;

	int curveDegree = curve.getDegree();

	// calculate fitness basing on the degree of polynomial
	switch (curveDegree)
	{
		case 2:
			fcnPtr = isPointPositiveSecondDegree;
			break;
		case 3:
			fcnPtr = isPointPositiveThirdDegree;
			break;
		case 4:
			fcnPtr = isPointPositiveFourthDegree;
			break;
		case 5:
			fcnPtr = isPointPositiveFifthDegree;
			break;
		default:
			std::cout << "Fitness calculation is impossible for given degree\n";
			return 0.0;	
	}

	int positivesetSize = positiveSet.getPointsetSize();
	int negativesetSize = negativeSet.getPointsetSize();

	// Iterate throught the positive set
	for (int i = 0; i < positivesetSize; i++)
		if (fcnPtr(positiveSet.getPoint(i).getX(), positiveSet.getPoint(i).getY(), curve))
			fitnessScore++;

	// Iterate throught the negative set
	for (int i = 0; i < negativesetSize; i++)
		if (!(fcnPtr(negativeSet.getPoint(i).getX(), negativeSet.getPoint(i).getY(), curve)))
			fitnessScore++;

	//std::cout << "fitness score = " << fitnessScore << ", number of points = " 
		//<< positivesetSize + negativesetSize << std::endl;


	double finalFitness = (double)fitnessScore / (positivesetSize + negativesetSize);

	return finalFitness;
}

bool isPointPositiveSecondDegree(double x, double y, Curve &curve)
{
	return (y > (curve.getCoefficientAt(0)->getNumber() * pow(x, 2.0) +
		curve.getCoefficientAt(1)->getNumber() * x + curve.getCoefficientAt(2)->getNumber()));
}

bool isPointPositiveThirdDegree(double x, double y, Curve &curve)
{
	return (y > (curve.getCoefficientAt(0)->getNumber() * pow(x, 3.0) +
		curve.getCoefficientAt(1)->getNumber() * pow(x, 2.0) + curve.getCoefficientAt(2)->getNumber() * x
		+ curve.getCoefficientAt(3)->getNumber()));
}

bool isPointPositiveFourthDegree(double x, double y, Curve &curve)
{
	return (y > (curve.getCoefficientAt(0)->getNumber() * pow(x, 4.0) +
		curve.getCoefficientAt(1)->getNumber() * pow(x, 3.0) + curve.getCoefficientAt(2)->getNumber() * pow(x, 2.0)
		+ curve.getCoefficientAt(3)->getNumber() * x + curve.getCoefficientAt(4)->getNumber()));
}

bool isPointPositiveFifthDegree(double x, double y, Curve &curve)
{
	return (y > (curve.getCoefficientAt(0)->getNumber() * pow(x, 5.0) +
		curve.getCoefficientAt(1)->getNumber() * pow(x, 4.0) + curve.getCoefficientAt(2)->getNumber() * pow(x, 3.0)
		+ curve.getCoefficientAt(3)->getNumber() * pow(x, 2.0) + curve.getCoefficientAt(4)->getNumber() * x + 
		curve.getCoefficientAt(5)->getNumber()));
}

std::vector<Curve*> createMatingPool(Population &population)
{
	std::vector<Curve*> *matingPool = new std::vector<Curve*>();

	for (int i = 0; i < population.getPopulationSize(); i++)
	{
		// Calculate how much pieces ha	ve curve basing of the fitness;
		int poolFraction = static_cast<int>(population.getCurveAt(i)->getFitness() * 100);
		for (int j = 0; j < poolFraction; j++)
		{
			matingPool->push_back(population.getCurveAt(i));
		}

	}

	return *matingPool;
}


// Crossover with binary exchange of genes
//Curve* crossoverParents(Curve &parent1, Curve &parent2, double crossoverRate)
//{
//	// a midpoint for taking genes from parent
//	int genomeSize = parent1.getCoefficientAt(0)->getBinaryRep().size();
//	int midpoint = floor(genomeSize * crossoverRate);
//
//	std::vector<Coefficient*> *childCoefficients = new std::vector<Coefficient*>();
//
//	int coefficientNum = parent1.getDegree() + 1;
//
//	for (int i = 0; i < coefficientNum; i++)
//	{
//		std::deque<int> parent1genes = parent1.getCoefficientAt(i)->getBinaryRep();
//		std::deque<int> parent2genes = parent2.getCoefficientAt(i)->getBinaryRep();
//		std::deque<int> childGenes;
//
//		for (int k = 0; k < genomeSize; k++)
//		{
//			if (k < midpoint) childGenes.push_back(parent1genes.at(k));
//			else childGenes.push_back(parent2genes.at(k));
//		}
//
//		childCoefficients->push_back(new Coefficient(childGenes));
//	}
//
//	return new Curve(childCoefficients);
//}


// Crossover with binary exchange of genes
//Curve* crossoverParents(Curve &parent1, Curve &parent2, double crossoverRate)
//{
//	// a midpoint for taking genes from parent
//	int genomeSize = parent1.getCoefficientAt(0)->getBinaryRep().size();
//	int midPoint = floor(genomeSize * crossoverRate);
//
//	std::vector<Coefficient*> *childCoefficients = new std::vector<Coefficient*>();
//
//	int coefficientNum = parent1.getDegree() + 1;
//
//	for (int i = 0; i < coefficientNum; i++)
//	{
//		std::deque<int> parent1genes = parent1.getCoefficientAt(i)->getBinaryRep();
//		std::deque<int> parent2genes = parent2.getCoefficientAt(i)->getBinaryRep();
//		std::deque<int> childGenes;
//
//		for (int k = 0; k < genomeSize; k++)
//		{
//			if (k < midPoint) childGenes.push_back(parent1genes.at(k));
//			else childGenes.push_back(parent2genes.at(k));
//		}
//
//		childCoefficients->push_back(new Coefficient(childGenes));
//	}
//
//	return new Curve(childCoefficients);
//}

// Crossover with binary exchange of genes
Curve* crossoverParents(Curve &parent1, Curve &parent2, double crossoverRate)
{
	// a midpoint for taking genes from parent
	int coefNum = parent2.getDegree() + 1;
	int midPoint = static_cast<int>(floor(coefNum * crossoverRate));

	std::vector<Coefficient*> *childCoefficients = new std::vector<Coefficient*>();

	for (int i = 0; i < coefNum; i++)
	{
		if (i < midPoint) childCoefficients->push_back(new Coefficient(parent1.getCoefficientAt(i)->getNumber()));
		else childCoefficients->push_back(new Coefficient(parent2.getCoefficientAt(i)->getNumber()));
	}

	return new Curve(childCoefficients);
}

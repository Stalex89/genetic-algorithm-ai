#include "RandomNumberGenerator.h"
#include "stdafx.h"

// Generates random integer number from min to max using Mersenne Twister
int getRandomNumber(int min, int max)
{
	static std::random_device rd;
	static std::mt19937 mersenne{ rd() };
	static const double fraction = 1.0 / (static_cast<double>(mersenne.max()) + 1.0);
	return min + static_cast<int>((max - min + 1) * (mersenne() * fraction));
}

double getRandomNumber(double min, double max)
{
	static std::random_device rd;
	static std::mt19937 mersenne{ rd() };
	static const double fraction = 1.0 / (static_cast<double>(mersenne.max()) + 1.0);
	return min + ((max - min + 1) * (mersenne() * fraction));
}

//float getFloatBetweenZeroAndOne()
//{
//	static std::random_device rd;
//	static std::mt19937 mersenne{ rd() };
//	std::uniform_real_distribution<float> dis(0.0, 1.0);
//	return dis(mersenne);
//}

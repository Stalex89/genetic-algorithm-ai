#pragma once
#include <deque>


// Assistant functions to convert decimal to binary or vice versa
int binaryToDecimal(std::deque<int> bits);
std::deque<int> decimalToBinary(int number);


// Gene (one element position in chromosome)
class Coefficient
{
	int m_number;
	std::deque<int> m_binaryRep;

public:
	Coefficient(int min, int max, bool canBeZero);
	Coefficient(int number);
	Coefficient(std::deque<int> binaryNum);
	void setNumber(int number);
	void mutateCoefficient(std::array<int, 8> mutationBits);
	void mutateCoefficient();
	int getNumber();
	std::deque<int> getBinaryRep();
	~Coefficient();
	void printBinary();
};


#include "stdafx.h"
#include "Coefficient.h"
#include "RandomNumberGenerator.h"
#include <bitset>
#include <deque>
#include <cmath>

std::deque<int> decimalToBinary(int number);
int binaryToDecimal(std::deque<int> bits);
void invertBit(int &bit);

// Generates random coefficient in binary representation (range between -127 to 127)
Coefficient::Coefficient()
{
	m_number = getRandomNumber(1, 20);
	m_binaryRep = decimalToBinary(m_number);
}

// Generates coefficient with decimal number provided
Coefficient::Coefficient(int number) : m_number(number)
{
	m_binaryRep = decimalToBinary(m_number);
}

// Generates coefficient with binary number provided
Coefficient::Coefficient(std::deque<int> binaryNum) : m_binaryRep(binaryNum)
{
	m_number = binaryToDecimal(m_binaryRep);
}

Coefficient::~Coefficient()
{

}

// Converts decimal number into binary representation
std::deque<int> decimalToBinary(int number)
{
	std::deque<int> binNumber;
	int num = abs(number);
	int remainder;

	for (int i = 0; i < 8; i++)
	{
		if (num != 0)
		{
			remainder = num % 2;
			num /= 2;
			binNumber.push_front(remainder);
		}
		else
			binNumber.push_front(0);
	}
	// if number is negative
	if(number < 0)
	{
		for (unsigned int i = 0; i < binNumber.size(); i++)
			invertBit(binNumber.at(i));

		for (unsigned int i = binNumber.size() - 1; i >= 0; i--)
		{
			if (binNumber.at(i) == 0)
			{
				binNumber.at(i) = 1;
				break;
			}
			else 
				binNumber.at(i) = 0;
		}
	}
	return binNumber;
}

// Converts binary representation into decimal
int binaryToDecimal(std::deque<int> bits)
{
	bool isNegative = false;
	// if the most significant bit is 1 so it is negative number, bits should be inverted and add 1 to less significant bit
	if (bits.at(0) == 1)
	{
		isNegative = true;
		for (unsigned int i = 0; i < bits.size(); i++)
			invertBit(bits.at(i));

		for (unsigned int i = bits.size() - 1; i >= 0; i--)
		{
			if (bits.at(i) == 0)
			{
				bits.at(i) = 1;
				break;
			}
			else
				bits.at(i) = 0;
		}
	}

	int val = 0;
	int value_to_add = 1;
	for (int i = bits.size()-1; i >= 0; i--)
	{
		if (bits.at(i) == 1)
			val += value_to_add;
		value_to_add *= 2;
	}
	return isNegative ? -val : val;
}

void invertBit(int &bit)
{
	if (bit == 1)
		bit = 0;
	else bit = 1;
}

void Coefficient::printBinary()
{
	std::string temp ="";
	for (unsigned int i = 0; i < m_binaryRep.size(); i++)
		temp += std::to_string(m_binaryRep.at(i));
	std::cout << "number = " << m_number << ", binary = " << temp;
}

void Coefficient::setNumber(int number)
{
	m_number = number;
	m_binaryRep = decimalToBinary(m_number);
}

int Coefficient::getNumber()
{
	return m_number;
}

std::deque<int> Coefficient::getBinaryRep()
{
	return m_binaryRep;
}

void Coefficient::mutateCoefficient(std::array<int, 8> mutationBits)
{
	for (unsigned int i = 0; i < m_binaryRep.size(); i++)
		if (mutationBits.at(i) == 1)
		{
			//std::cout << "mutate bit #" << i << '\n';
			invertBit(m_binaryRep.at(i));
		}
	m_number = binaryToDecimal(m_binaryRep);	
}



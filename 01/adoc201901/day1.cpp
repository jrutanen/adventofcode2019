#include "adoc2019.h"

using namespace std;
/*
--- Day 1: The Tyranny of the Rocket Equation ---
Fuel required to launch a given module is based on its mass. Specifically,
to find the fuel required for a module, take its mass, divide by three,
round down, and subtract 2.

The Fuel Counter-Upper needs to know the total fuel requirement. To find it,
individually calculate the fuel needed for the mass of each module
(your puzzle input), then add together all the fuel values.

What is the sum of the fuel requirements for all of the modules on your
spacecraft?

*/

int calculateFuelMass(const int moduleMass)
{
	//int currentMass = moduleMass;
	int totalFuelMass = 0;
	int fuelMass = calculateRequiredFuel(moduleMass);

	while (fuelMass > 0)
	{
		totalFuelMass = totalFuelMass + fuelMass;
		fuelMass = calculateRequiredFuel(fuelMass);
	}

	return totalFuelMass;
}

int calculateRequiredFuel(const int mass)
{
	int requiredFuel = (mass / 3) - 2;
	return requiredFuel;
}

vector<int> readValues(const string fileName)
{
	vector<int> result;

	//open file
	ifstream dataFile(fileName.c_str());

	if (!dataFile)
	{
		cerr << "Can't open file: " << fileName << endl;
		return  result;
	}

	string row;
	while (getline(dataFile, row))
	{
		if (row.size() > 0)
		{
			result.push_back(stoi(row));
		}
	}
	return result;
}

int calculateTotalFuel(const string fileName, int part)
{
	int totalFuel = 0;
	//Add fuel for the mass of the modules
	vector<int> values = readValues(fileName);
	for (auto const& value : values)
	{
		int fuelMass = calculateRequiredFuel(value);
		if (part == 1)
		{
			totalFuel += fuelMass;
		}
		else
		{
			totalFuel += (fuelMass + calculateFuelMass(fuelMass));
		}
	}

	return totalFuel;
}

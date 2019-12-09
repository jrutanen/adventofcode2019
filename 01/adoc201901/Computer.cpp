#include "Computer.h"

Computer::Computer()
{
}

void Computer::loadProgram(string fileName)
{
	//open file
	ifstream dataFile(fileName.c_str());

	if (!dataFile)
	{
		cerr << "Can't open file: " << fileName << endl;
	}

	//read code row
	string row;
	getline(dataFile, row);
	int sPos = 0, ePos = 0;
	int lastIndex = row.length() - 1;

	//Add comma separated values to a vector
	vector<int> result;
	while (ePos != -1)
	{
		ePos = row.find(',', ePos + 1);
		int value = (ePos != -1) ? stoi(row.substr(sPos, ePos - sPos)) : stoi(row.substr(sPos, ePos - sPos));
		result.push_back(value);
		sPos = ePos + 1;
	}

	//Copy values to the initialMemory of the computer
	this->initialMemory = result;
	this->workingMemory = result;
}

void Computer::calculateOutput()
{
	this->workingMemory = this->calculateOutput(this->workingMemory);
}


vector<int> Computer::calculateOutput(vector<int> program)
{
	if (program.size() < 4) return program;

	int iterations = program.size() / 4;
	for (int i = 0; i < iterations; ++i)
	{
		int operation = program[i * 4];
		int input0 = program[i * 4 + 1];
		int input1 = program[i * 4 + 2];
		int output = program[i * 4 + 3];

		switch (operation)
		{
			//addition
		case 1:
			program[output] = program[input0] + program[input1];
			break;
			//multiplication
		case 2:
			program[output] = program[input0] * program[input1];
			break;
			//halt
		case 99:
			i = iterations;
			break;
		}
	}
	return program;
}

int Computer::getValueAtLocation(int i)
{
	if (this->workingMemory.size() < i)
	{
		cout << "Out of Memory Error";
		return -1;
	}
	else
	{
		return this->workingMemory[i];
	}
}

bool Computer::setValueAtLocation(int i, int value)
{
	if (this->workingMemory.size() < i)
	{
		cout << "Out of Memory Error";
		return false;
	}
	else
	{
		this->workingMemory[i] = value;
		return true;
	}
}

void Computer::resetMemory()
{
	this->workingMemory = this->initialMemory;
}


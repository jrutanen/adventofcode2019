#include "adoc2019.h"
// Include boost::for is_any_of
//#include <boost/algorithm/string/classification.hpp>
// Include for boost::split
//#include <boost/algorithm/string/split.hpp>

using namespace std;

vector<int> intcodeRun(vector<int> program)
{
	if (program.size() < 4) return program;

	int iterations = program.size() / 4;
	for(int i = 0; i < iterations; ++i)
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

vector<int> readIntcodeFile(string fileName)
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
	getline(dataFile, row);
	int sPos = 0, ePos = 0;
	int lastIndex = row.length() - 1;
	cout << row << endl;
	while (ePos != -1)
	{
		ePos = row.find(',', ePos + 1);
		int value = (ePos != -1) ? stoi(row.substr(sPos, ePos - sPos)) : stoi(row.substr(sPos, ePos - sPos));
		result.push_back(value);
		sPos = ePos + 1;
	}

	/*
		Once you have a working computer, the first step is to restore the
		gravity assist program (your puzzle input) to the "1202 program alarm"
		state it had just before the last computer caught fire. To do this,
		before running the program, replace position 1 with the value 12 and
		replace position 2 with the value 2.
	*/
	result[1] = 12;
	result[2] = 2;

	return result;
}
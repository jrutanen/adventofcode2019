#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Computer
{
	public:
		Computer();
		void loadProgram(string fileName);
		void calculateOutput();
		int getValueAtLocation(int i);
		bool setValueAtLocation(int i, int value);
		void resetMemory();
	private:
		vector<int> initialMemory;
		vector<int> workingMemory;
		vector<int> calculateOutput(vector<int> program);
};


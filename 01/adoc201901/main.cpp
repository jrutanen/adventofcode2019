#include <iostream>
#include "../adoc201901/adoc2019.h"
#include "../adoc201901/Computer.h"

using namespace std;


int main()
{
	//Day 1, part 1
	string file = "F:\\code\\advent\\adventofcode2019\\01\\adoc201901\\day01_p01_input.txt";
	cout << "Required Fuel is: " << calculateTotalFuel(file, 1) << endl;

	//Day 1, part 2
	cout << "Required Fuel is: " << calculateTotalFuel(file, 2) << endl;

	//Day 2, part 1
	file = "F:\\code\\advent\\adventofcode2019\\01\\adoc201901\\day02_p01_input.txt";
	Computer computer;
	computer.loadProgram(file);
	computer.setValueAtLocation(1, 12);
	computer.setValueAtLocation(2, 2);
	computer.calculateOutput();
	cout << "Position 0: " << computer.getValueAtLocation(0) << endl;
	//Day 2, part 1
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			computer.resetMemory();
			computer.setValueAtLocation(1, i);
			computer.setValueAtLocation(2, j);
			computer.calculateOutput();
			if (computer.getValueAtLocation(0) == 19690720)
			{
				cout << "Noun: " << 100 * i << " verb: " << j 
					 << " Result: " << 100 * i + j << endl;
				break; 
			}
		}
		if (computer.getValueAtLocation(0) == 19690720)
		{
			break;
		}
	}

	return 0;
}

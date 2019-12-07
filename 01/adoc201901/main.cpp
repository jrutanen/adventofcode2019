#include <iostream>
#include "../adoc201901/adoc2019.h"

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
	cout << "Position 0: " << intcodeRun(readIntcodeFile(file))[0] << endl;

	return 0;
}

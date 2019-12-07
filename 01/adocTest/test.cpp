#include <string>
#include "pch.h"
#include "../adoc201901/adoc2019.h"

TEST(Day01, Part01) {
	/*
	For a mass of 12, 2
	For a mass of 14, 2
	For a mass of 1969, 654
	For a mass of 100756, 33583
	*/
	std::string file = "F:\\code\\advent\\adventofcode2019\\01\\adocTest\\day01p1TestData.txt";
	EXPECT_EQ(calculateRequiredFuel(12), 2);
	EXPECT_EQ(calculateRequiredFuel(14), 2);
	EXPECT_EQ(calculateRequiredFuel(1969), 654);
	EXPECT_EQ(calculateRequiredFuel(100756), 33583);
//	EXPECT_EQ(calculateTotalFuel(file), 33583 + 654 + 2 + 2 +  );

	EXPECT_TRUE(true);
}
TEST(Day01, Part02) {
	/*
		A module of mass 14 requires 2 fuel. This fuel requires no further fuel (2 divided by 3
		and rounded down is 0, which would call for a negative fuel), so the total fuel required
		is still just 2.

		At first, a module of mass 1969 requires 654 fuel. Then, this fuel requires 216 more fuel
		(654 / 3 - 2). 216 then requires 70 more fuel, which requires 21 fuel, which requires 5
		fuel, which requires no further fuel. So, the total fuel required for a module of mass
		1969 is 654 + 216 + 70 + 21 + 5 = 966.

		The fuel required by a module of mass 100756 and its fuel is:
		33583 + 11192 + 3728 + 1240 + 411 + 135 + 43 + 12 + 2 = 50346.

	*/
	std::string file = "F:\\code\\advent\\adventofcode2019\\01\\adocTest\\day01p1TestData.txt";
	EXPECT_EQ(calculateFuelMass(2), 0);
	EXPECT_EQ(calculateFuelMass(1969), 966);
	EXPECT_EQ(calculateFuelMass(100756), 50346);

	EXPECT_TRUE(true);
}

TEST(Day02, Part01) {
	//op codes 1=addition, 2=multiplication, 99=halt
	std::vector<int> program0 = {1, 0, 0, 0, 99};
	std::vector<int> expected0 = { 2, 0, 0, 0, 99 };
	EXPECT_TRUE(intcodeRun(program0) == expected0);

	std::vector<int> program1 = { 2, 3, 0, 3, 99 };
	std::vector<int> expected1 = { 2, 3, 0, 6, 99 };
	EXPECT_TRUE(intcodeRun(program1) == expected1);

	std::vector<int> program2 = { 2, 4, 4, 5, 99, 0 };
	std::vector<int> expected2 = { 2, 4, 4, 5, 99, 9801 };
	EXPECT_TRUE(intcodeRun(program2) == expected2);

	std::vector<int> program3 = { 1, 1, 1, 4, 99, 5, 6, 0, 99 };
	std::vector<int> expected3 = { 30, 1, 1, 4, 2, 5, 6, 0, 99 };
	EXPECT_TRUE(intcodeRun(program3) == expected3);
}
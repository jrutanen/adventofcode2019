#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int calculateRequiredFuel(const int mass);
std::vector<int> readValues(const std::string fileName);
int calculateTotalFuel(const std::string fileName, int part);
int calculateFuelMass(const int fuelMass);
std::vector<int> intcodeRun(std::vector<int> program);
std::vector<int> readIntcodeFile(std::string filename);
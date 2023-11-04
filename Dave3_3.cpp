
// Roshni Dave. CS 10A. Sarkar S. Dave3_3.cpp.

/*
This program takes the start time and length of the call as input and calculates
the gross cost based on the rate structure. It applies the appropriate discounts
and calculates the tax. Also it displays the gross and net costs with two
decimal places.

*/
// This program calculates the cost of long-distance calls.

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
const double pricePerMinuteOriginal = 0.35; 
double pricePerMinute = pricePerMinuteOriginal;

// Regular price per minute with no discounts

const double federalTaxRate = 1.04;
double grossCost;
double netCost;

int numberOfMinutes;
int startTime;
//Get user information
std::cout << "Enter start time: ";
std::cin >> startTime;
std::cout << "Enter length of call in minutes: ";
std::cin >> numberOfMinutes;

if (startTime < 800 || startTime > 1800)
pricePerMinute *= 0.5;

if (numberOfMinutes > 60)
pricePerMinute -= pricePerMinute * 0.16;

grossCost = numberOfMinutes * pricePerMinuteOriginal;

netCost = pricePerMinute * numberOfMinutes * federalTaxRate;

std::cout << std::fixed << std::showpoint << std::setprecision(2);
std::cout << "Gross cost: $" << grossCost << std::endl;
std::cout << std::fixed << std::showpoint << std::setprecision(2);
std::cout << "Net Cost: $" << netCost << std::endl;
return 0;
}
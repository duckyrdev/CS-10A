
// Roshni Dave. CS 10A. Sarkar S. Dave2_2.cpp. 

/*
    This program calculates the optimal change in quarters, dimes, nickels, and pennies
    for a given amount in cents. It demonstrates the use of the modulus operator and integer division to efficiently determine the number of each coin needed to make the change.
    */


#include <iostream>

using namespace std;

int main() {

    // Declare variables
    int cents, quarters, dimes, nickels, pennies;

    // Prompt the user for the amount in cents
    cout << "Please enter the number of cents: ";
    cin >> cents;

    // Calculate the number of quarters
    quarters = cents / 25;
    cents = cents % 25;

    // Calculate the number of dimes
    dimes = cents / 10;
    cents = cents % 10;

    // Calculate the number of nickels
    nickels = cents / 5;
    cents = cents % 5;

    // The remaining cents are pennies
    pennies = cents;

    // Display change in ascending order
    cout << "\nChange displayed in ascending order\n";
    cout << "---------------------------\n";
    cout << "pennies: " << pennies << endl;
    cout << "nickels: " << nickels << endl;
    cout << "dimes: " << dimes << endl;
    cout << "quarters: " << quarters << endl;

    // Display change in descending order
    cout << "\nChange displayed in descending order\n";
    cout << "----------------------------\n";
    cout << "quarters: " << quarters << endl;
    cout << "dimes: " << dimes << endl;
    cout << "nickels: " << nickels << endl;
    cout << "pennies: " << pennies << endl;

    return 0;
}

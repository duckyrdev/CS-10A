
// Roshni Dave. CS 10A. Sarkar S. Dave2_3.cpp. 

/*
This C++ program converts a given amount in U.S. dollars to Japanese yen, South African rand, Israeli shekels, and European euros using the provided exchange rates as constants. It then displays the converted amounts in fixed-point notation with two decimal places of precision.
*/

#include <iostream>
#include <iomanip>  // For formatting output

using namespace std;

int main() {
    // Constants for currency conversion rates fromw website https://www.oanda.com/currency-converter/
    const double YEN_PER_DOLLAR = 95.1232;
    const double RAND_PER_DOLLAR = 15.0609;
    const double SHEKEL_PER_DOLLAR = 3.0210;
    const double EUROS_PER_DOLLAR = 0.8119;

    // Prompt the user for the amount in U.S. dollars
    double usdAmount;
    cout << "Amount of U.S. currency to convert: $";
    cin >> usdAmount;

    // Calculate converted amounts
    double yenAmount = usdAmount * YEN_PER_DOLLAR;
    double randAmount = usdAmount * RAND_PER_DOLLAR;
    double shekelAmount = usdAmount * SHEKEL_PER_DOLLAR;
    double eurosAmount = usdAmount * EUROS_PER_DOLLAR;

    // Display converted amounts with formatting
    cout << fixed << setprecision(2);  // Format for two decimal places
    cout << "\nFOREIGN CURRENCIES CONVERTED\n";
    cout << "----------------------------\n";
    cout << "$" << usdAmount << " = " << yenAmount << " Yen (JAPAN)\n";
    cout << "$" << usdAmount << " = " << randAmount << " Rand (SOUTH AFRICA)\n";
    cout << "$" << usdAmount << " = " << shekelAmount << " Shekel (ISRAEL)\n";
    cout << "$" << usdAmount << " = " << eurosAmount << " Euros (EUROPEAN UNION)\n";

    // Wait for user input before exiting
    cout << "\nPress any key to continue . . .";
    cin.ignore();
    cin.get();

    return 0;
}
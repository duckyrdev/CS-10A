// Roshni Dave. CS 10A. Sarkar S. Dave3_2.cpp. 

/*
This program first presents a menu of subscription packages to choose from and validates the user's input. Then, it calculates the total amount due based on the selected package and hours used, taking into account the usage quota for package C. Finally, it displays the total amount due with two decimal places.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const double packageA = 9.95;
    const double packageB = 14.95;
    const double packageC = 19.95;
    const double additionalRateA = 2.00;
    const double additionalRateB = 1.00;
    const int quotaC = 730;

    int choice;
    double hoursUsed, totalAmount;

    cout << "Select a subscription package:" << endl;
    cout << "1. Package A" << endl;
    cout << "2. Package B" << endl;
    cout << "3. Package C" << endl;
    cout << "4. Quit" << endl;

    cin >> choice;

    switch (choice) {
        case 1:
            cout << "How many hours were used? ";
            cin >> hoursUsed;

            if (hoursUsed > quotaC) {
                cout << "Usage quota not to exceed " << quotaC << " hours" << endl;
                totalAmount = packageA + (hoursUsed - 10) * additionalRateA;
            } else {
                totalAmount = packageA;
            }

            break;

        case 2:
            cout << "How many hours were used? ";
            cin >> hoursUsed;

            if (hoursUsed > quotaC) {
                cout << "Usage quota not to exceed " << quotaC << " hours" << endl;
                totalAmount = packageB + (hoursUsed - 20) * additionalRateB;
            } else {
                totalAmount = packageB;
            }

            break;

        case 3:
            cout << "How many hours were used? ";
            cin >> hoursUsed;

            if (hoursUsed > quotaC) {
                cout << "Usage quota not to exceed " << quotaC << " hours" << endl;
            }

            totalAmount = packageC;
            break;

        case 4:
            return 0;

        default:
            cout << "The valid choices are 1 through 4." << endl;
            cout << "Run the program again and select one of those." << endl;
            return 1;
    }

    cout << fixed << setprecision(2);
    cout << "The total amount due is $" << totalAmount << endl;

    return 0;
}

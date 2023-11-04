// Roshni Dave. CS 10A. Sarkar S. Dave5.cpp. 

/*
  Collatz Conjecture Program
  This C++ program takes a non-negative integer input greater than 0 and applies the Collatz conjecture rules,
  which involve dividing by 2 for even numbers and multiplying by 3 and adding 1 for odd numbers, until the
  value reaches 1. It counts and displays each intermediate value and the total number of steps taken.
  Input validation ensures a valid input is provided.
*/

#include <iostream>

using namespace std;

int main() {
    int c0, steps = 0;

    cout << "Enter a non-negative number greater than 0: ";
    cin >> c0;

    // Input validation
    while (c0 <= 0) {
        cout << "Invalid value input" << endl;
        cout << "Enter a non-negative number greater than 0: ";
        cin >> c0;
    }

    while (c0 != 1) {
        if (c0 % 2 == 0) {
            c0 /= 2;
        } else {
            c0 = 3 * c0 + 1;
        }

        cout << c0 << endl;
        steps++;
    }

    cout << "steps = " << steps << endl;

    return 0;
}

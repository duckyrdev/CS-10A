// Roshni Dave. CS 10A. Sarkar S. Dave2_1.cpp. 

 /*
    Random Addition Problem Generator
    This C++ program serves as a math tutor for addition problems. It generates two random three-digit numbers, displays them as an addition problem, and waits for the user to press Enter to reveal the correct solution.

    */


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    // Generate two random numbers between 100 and 999
    int num1 = rand() % 900 + 100;
    int num2 = rand() % 900 + 100;

    // Calculate the correct answer
    int correctAnswer = num1 + num2;

    // Display the numbers to be added
    cout << "   " << num1 << endl;
    cout << " + " << num2 << endl;
    cout << "-------" << endl;

    // Prompt the user to press Enter to see the answer
    cout << "Press Enter to see the answer . . .";
    cin.get();  // Wait for the user to press Enter

    // Display the correct solution
    cout << "   " << num1 << endl;
    cout << " + " << num2 << endl;
    cout << "-------" << endl;
    cout << "   " << correctAnswer << endl;

    return 0;
}

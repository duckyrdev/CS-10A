2// Roshni Dave. CS 10A. Sarkar S. Dave_Patern2.cpp

#include <iostream>

int main() {
    const int numRows = 9;

    // Pattern A
    std::cout << "Pattern A\n";
    for (int row = 1; row <= numRows; row++) {
        for (int stars = 1; stars <= row * 2 - 1; stars++) {
            std::cout << "+";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Pattern B
    std::cout << "Pattern B\n";
    for (int row = numRows; row >= 1; row--) {
        for (int stars = 1; stars <= row * 2 - 1; stars++) {
            std::cout << "+";
        }
        std::cout << std::endl;
    }

    return 0;
}
/*
For both Pattern A and Pattern B, we use nested for loops.
The outer loop controls the rows, with the loop variable row ranging from 1 to 9 in Pattern A and from 9 to 1 in Pattern B.
The inner loop controls the number of stars in each row. The number of stars starts at 1 and increases by 2 in each iteration until it reaches row * 2 - 1.
The std::cout statements are used to print the plus signs ('+') to form the patterns.

  */
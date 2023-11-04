// Roshni Dave. CS 10A. Sarkar S. Dave6_1.cpp.

// This program counts the number of words in a file using while loops, std cout, and nesting.

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

bool isWordCharacter(char c) {
    return isalnum(c) || c == '&' || c == '%';
}

int main() {
    std::cout << "*** A SIMPLE FILE PROCESSING PROGRAM ***" << std::endl;

    while (true) {
        std::string filename;
        std::cout << "Enter a filename or type 'quit' to exit: ";
        std::cin >> filename;

        if (filename == "quit") {
            std::cout << "Now exiting the program..." << std::endl;
            break;
        }

        std::ifstream file(filename);

        if (!file) {
            std::cout << "File not found. Enter the correct filename." << std::endl;
            continue;
        }

        std::cout << filename << " data" << std::endl;
        std::cout << "***********************" << std::endl;

        int wordCount = 0;
        char c;

        while (file.get(c)) {
            std::cout << c;

            // Count words
            if (isWordCharacter(c)) {
                while (isWordCharacter(c)) {
                    if (!file.get(c)) {
                        break;
                    }
                }
                wordCount++;
            }
        }

        std::cout << std::endl << "***********************" << std::endl;
        std::cout << filename << " has " << wordCount << " words." << std::endl;
    }

    return 0;
}

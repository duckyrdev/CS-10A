// Roshni Dave. CS 10A. Sarkar S. Dave6_2.cpp.

//This  program allows users to input a filename containing a list of numbers, reads and displays the numbers from the file, calculates the total count, sum, and average of the numbers, and presents the results in a user-friendly manner, preserving the original formatting of the file's contents. It includes file validation to ensure accurate processing, and the output printts both the file contents and the  summary.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::string filename;
    std::ifstream inputFile;
    std::vector<int> numbers;

    bool fileOpened = false;

    while (!fileOpened) {
        // Prompt the user for the file name
        std::cout << "To process data, enter the filename: ";
        std::cin >> filename;

        // Open the file
        inputFile.open(filename);

        // Check if the file opened successfully
        if (!inputFile) {
            std::cout << "File not found. Enter the correct filename." << std::endl;
        } else {
            fileOpened = true;
        }
    }

    // Display the file contents with each number on a new line
    std::cout << "Contents of " << filename << ":" << std::endl;
    int num;
    while (inputFile >> num) {
        numbers.push_back(num);
        std::cout << num << std::endl;
    }

    // Close the file
    inputFile.close();

    // Read numbers from the file and calculate statistics
    int sum = 0;
    int count = numbers.size();

    for (int num : numbers) {
        sum += num;
    }

    // Calculate the average
    double average = static_cast<double>(sum) / count;

    // Display the results
    std::cout << "Data in " << filename << " has been successfully read and processed..." << std::endl;
    std::cout << "Number of numbers: " << count << std::endl;
    std::cout << "Sum of the numbers: " << sum << std::endl;
    std::cout << "Average of the numbers: " << average << std::endl;

    return 0;
}

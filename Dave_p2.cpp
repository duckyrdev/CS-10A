// Roshni Dave. CS 10A. Sarkar S. Dave_p2.cpp. 

/*
 * Math Skill Builder Program
 * 
 * This interactive program is designed to help users practice and enhance their math skills 
 * through a series of arithmetic, geometry, and statistics problems. It utilizes a menu-driven 
 * approach, allowing users to select the type of math problems they wish to solve. The program 
 * generates random operands within specified ranges and evaluates user responses, providing 
 * immediate feedback on correctness. Upon completion of each set of problems, it displays a 
 * summary report of the user's performance, including the total number of correct answers 
 * and a percentage score. Randomization, input validation, and a simple UI are key features 
 * of the system, making it both user-friendly and effective for math practice.
 */


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

// function prototypes
void programInfo();
void mathSkillBuilderMenu(/*out*/ int& choice);
void processProbSets(/*in*/ int choice, /*out*/ int& numProbSets, /*out*/ int& numCorrect);
void printReport(/*in*/ int choice,/*in*/ int numProbSets,/*in*/ int numCorrect);
int getNumSets();
void arithmeticProbSet(/*in*/ int numProbSets, /*out*/ int& correctCount);
void geometryProbSet(/*in*/ int numProbSets, /*out*/ int& correctCount);
void statisticsProbSet(/*in*/ int numProbSets, /*out*/ int& correctCount);
double getUserInput();
void checkAnswer(/*in*/ double userAnswer, /*in*/ double correctAnswer, /*out*/ int& correctCount);
void generateOperands(/*out*/ int& num1);
void generateOperands(/*out*/ int& num1, /*out*/ int& num2);
void generateOperands(/*out*/ int& num1, /*out*/ int& num2, /*out*/ int& num3);

// global constants
const int PROBSPERSET = 4;
const int MIN_NUM = 1, MAX_NUM = 10;
const double PI = 3.14159265358979323846;
const int MAX_ITEMS = 100; // For statistics problems

int main() {
    srand(static_cast<unsigned int>(time(0))); // seed the random number generator
    int choice, numProbSets, numCorrect;
    cout << showpoint << fixed << setprecision(2);  // Set output formatting for floating point numbers.

    programInfo();  // Display program info
    do { // Main loop for the menu-driven interface.
        mathSkillBuilderMenu(choice);  // Show menu and get user choice
        if (choice == 0) break;  // Exit condition
        processProbSets(choice, numProbSets, numCorrect);  // Process problem sets
        printReport(choice, numProbSets, numCorrect);  // Print the report
    } while (choice != 0);  // Continue until the user chooses to exit.

    cout << "Thank you for using the Math Skill Builder. Goodbye!" << endl;
    return 0;
}

void programInfo() {
    cout << "Welcome to the Math Skill Builder Program!" << endl;
    cout << "You will be presented with a series of math problems " 
         << "ranging from arithmetic to geometry." << endl;
    cout << "Enter the correct answer to each problem. " 
         << "At the end, your performance will be evaluated." << endl;
}

void mathSkillBuilderMenu(int& choice) { 
  // Presents the main menu to the user and handles input validation.

    cout << "\nPlease choose the skill set to practice:" << endl;
    cout << "1. Arithmetic" << endl;
    cout << "2. Geometry" << endl;
    cout << "3. Statistics" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice (0-3): ";
    cin >> choice;
    if (cin.fail() || choice < 0 || choice > 3) {
        cout << "Invalid choice, please enter a number between 0 and 3." << endl;
        cin.clear();  // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore wrong input
        choice = -1;  // Set choice to invalid and prompt again
    }
}

void processProbSets(int choice, int& numProbSets, int& numCorrect) {
  // Coordinates the problem set generation based on user choice.

    numCorrect = 0;
    numProbSets = getNumSets();

    switch (choice) {
        case 1:
            arithmeticProbSet(numProbSets, numCorrect);
            break;
        case 2:
            geometryProbSet(numProbSets, numCorrect);
            break;
        case 3:
            statisticsProbSet(numProbSets, numCorrect);
            break;
        default:
            cout << "Invalid choice. No problem sets processed." << endl;
            break;
    }
}

void printReport(int choice, int numProbSets, int numCorrect) {
  // Report formatting and calculation of the percentage score.
    double percentage = (static_cast<double>(numCorrect) / (numProbSets * PROBSPERSET)) * 100;
    cout << "=================================================================" << endl;
    switch (choice) {
        case 1:
            cout << "Basic Arithmetic Skill Set: ";
            break;
        case 2:
            cout << "Basic Geometry Skill Set: ";
            break;
        case 3:
            cout << "Basic Statistics Skill Set: ";
            break;
        default:
            cout << "No skill set chosen. " << endl;
            return;
    }
    cout << numCorrect << " out of " << numProbSets * PROBSPERSET 
         << " (" << percentage << "%) correct." << endl;
    cout << "=================================================================" << endl;
}

int getNumSets() {
    int sets;
    cout << "How many sets of " << PROBSPERSET << " problems would you like to do? ";
    cin >> sets;
    while (cin.fail() || sets <= 0) {
        cout << "Invalid input. Please enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> sets;
    }
    return sets;
}

void arithmeticProbSet(int numProbSets, int& correctCount) {
    int num1, num2, choice;
    double userAnswer, correctAnswer;
    for (int set = 0; set < numProbSets; ++set) {
        for (int prob = 0; prob < PROBSPERSET; ++prob) {
            choice = rand() % 4; // Now includes addition (0), subtraction (1), multiplication (2), division (3)
            generateOperands(num1, num2); // Generate two integer operands
            switch (choice) {
                case 0: // Addition
                    correctAnswer = num1 + num2;
                    cout << "What is " << static_cast<double>(num1) << " + " << static_cast<double>(num2) << "? ";
                    break;
                case 1: // Subtraction
                    correctAnswer = num1 - num2;
                    cout << "What is " << static_cast<double>(num1) << " - " << static_cast<double>(num2) << "? ";
                    break;
                case 2: // Multiplication
                    correctAnswer = num1 * num2;
                    cout << "What is " << static_cast<double>(num1) << " * " << static_cast<double>(num2) << "? ";
                    break;
                case 3: // Division
                    while (num2 == 0) { // Ensure denominator is not zero
                        num2 = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
                    }
                    correctAnswer = num1 / num2;
                    cout << "What is " << static_cast<double>(num1) << " / " << static_cast<double>(num2) << "? ";
                    break;
            }
            userAnswer = getUserInput();
            // Since we are only dealing with integers, we can check for correctness by comparing the truncated values
            checkAnswer(static_cast<int>(userAnswer), static_cast<int>(correctAnswer), correctCount);
        }
    }
}

void geometryProbSet(int numProbSets, int& correctCount) {
    int choice, base, height, length, width, radius;
    double userAnswer, correctAnswer;
    for (int set = 0; set < numProbSets; ++set) {
        for (int prob = 0; prob < PROBSPERSET; ++prob) {
            choice = rand() % 3; // Choose a random geometry problem
            switch (choice) {
                case 0: // Circle Area
                    generateOperands(radius);
                    correctAnswer = PI * pow(radius, 2);
                    cout << "Calculate the area of a circle given radius: " << radius << endl;
                    break;
                case 1: // Triangle Area
                    generateOperands(base, height);
                    correctAnswer = 0.5 * base * height;
                    cout << "Calculate the area of a triangle given base " << base << " and height " << height << endl;
                    break;
                case 2: // Rectangle Perimeter
                    generateOperands(length, width);
                    correctAnswer = 2 * (length + width);
                    cout << "Calculate the perimeter of a rectangle given length " << length << " and width " << width << endl;
                    break;
            }
            userAnswer = getUserInput();
            checkAnswer(userAnswer, correctAnswer, correctCount);
        }
    }
}


void statisticsProbSet(int numProbSets, int& correctCount) {
    int numRed, numBlue;
    double userAnswer, correctAnswer;
    cout << "Calculate the probability of drawing a red item from a bag:" << endl;
    for (int set = 0; set < numProbSets; ++set) {
        for (int prob = 0; prob < PROBSPERSET; ++prob) {
            numRed = rand() % MAX_ITEMS + 1; // At least 1 red item
            numBlue = rand() % MAX_ITEMS + 1; // At least 1 blue item
            correctAnswer = static_cast<double>(numRed) / (numRed + numBlue);
            cout << "In a bag of " << numRed << " red and " << numBlue << " blue items, what is the probability of drawing a red item? ";
            userAnswer = getUserInput();
            checkAnswer(userAnswer, correctAnswer, correctCount);
        }
    }
}

double getUserInput() {
    double input;
    while (true) {
        cin >> input;
        if (cin.fail()) {
            cin.clear(); // Clears the error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discards the input buffer
            cout << "Invalid input. Please enter a number: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discards any additional input
            break;
        }
    }
    return input;
}
void checkAnswer(double userAnswer, double correctAnswer, int& correctCount) {
    // We will use a precision of .01 to compare the user's answer to the correct answer
    if (fabs(correctAnswer - userAnswer) < 0.01) {
        cout << "Correct!" << endl;
        ++correctCount;
    } else {
        cout << "Incorrect. Correct answer displayed with precision of .01 = " 
             << setprecision(2) << fixed << correctAnswer << "." << endl;
    }
}

void generateOperands(int& num1) {
    num1 = MIN_NUM + (rand() % (MAX_NUM - MIN_NUM + 1));
}

void generateOperands(int& num1, int& num2) {
    num1 = MIN_NUM + (rand() % (MAX_NUM - MIN_NUM + 1));
    num2 = MIN_NUM + (rand() % (MAX_NUM - MIN_NUM + 1));
}

void generateOperands(int& num1, int& num2, int& num3) {
    num1 = MIN_NUM + (rand() % (MAX_NUM - MIN_NUM + 1));
    num2 = MIN_NUM + (rand() % (MAX_NUM - MIN_NUM + 1));
    num3 = MIN_NUM + (rand() % (MAX_NUM - MIN_NUM + 1));
}


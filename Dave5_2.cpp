// Roshni Dave. CS 10A. Sarkar S. Dave5.cpp. 

/*
Drawing Squares Program, see bottom of code for description in paragraphs.
*/


#include <iostream>
#include <limits>

using namespace std;

int main() {
    cout << "**************** Drawing Squares Program ****************************" << endl;
    cout << "* Algorithm generates a hollow square, using the character +, - and | *" << endl;
    cout << "* Acceptable size dimension: Any value from 3 to 20. Choose carefully.  *" << endl;
    cout << "***********************************************************************" << endl;

    char tryAgain;
    do {
        int sideSize;
        cout << "Side size = ";
        cin >> sideSize;

        // Check if the input is valid
        if (cin.fail() || sideSize < 3 || sideSize > 20) {
            cout << "OOPS! Looks like you typed some bad data here!" << endl;
            cout << "The acceptable dimension should range from 3 to 20, so choose carefully..." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // Print the hollow square with corners as "+", horizontal sides as "-", and vertical sides as "|"
        for (int i = 1; i <= sideSize; i++) {
            for (int j = 1; j <= sideSize; j++) {
                if (i == 1 || i == sideSize) {
                    cout << (j == 1 || j == sideSize ? "+" : "-");
                } else {
                    cout << (j == 1 || j == sideSize ? "|" : " ");
                }
            }
            cout << endl;
        }

        cout << "To try my shape generator program again type Y for Yes and N for No: ";
        cin >> tryAgain;
    } while (tryAgain == 'Y' || tryAgain == 'y');

    cout << "Now exiting the shape generator program......." << endl;

    return 0;
}


/* Algorithm Explanation:
The program first welcomes the user and explains its purpose. It uses a do-while loop to repeatedly prompt the user for input and generate the desired shape. The user's input is validated to ensure it's a positive integer within the range of 3 to 20. Inside the loop, two nested for loops are used to generate the hollow square. The outer loop iterates over the rows of the square, and the inner loop iterates over the columns. Depending on the current row and column, it prints either "+", "-", or "|" to create the desired pattern.

After generating the square, the program asks the user if they want to try again. The loop continues until the user enters 'N' or 'n'. Finally, the program exits with a message. Variable names are chosen to be descriptive. The input validation uses cin.fail() to check for invalid input and clears the input stream as needed. The loops are pre-test loops, ensuring at least one iteration, and generate the pattern character by character to create the desired output.
*/

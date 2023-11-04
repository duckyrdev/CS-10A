
// Roshni Dave. CS 10A. Sarkar S. Dave2_3.cpp. 

/*
This C++ program  prompts the user to input a letter of the alphabet and outputs the corresponding letter using the ROT13 coding scheme. It also includes input validation to handle characters not included in the ROT13 coding scheme.
*/

#include <iostream>
using namespace std;

int main() {
    char inputChar;
    cout << "Enter a letter (A - Z): ";
    cin >> inputChar;
    
    switch (inputChar) {
        case 'A': case 'a':
            cout << "ROT13 Caesar Cipher for " << inputChar << " -> N." << endl;
            break;
        case 'B': case 'b':
            cout << "ROT13 Caesar Cipher for " << inputChar << " -> O." << endl;
            break;
        case 'C': case 'c':
            cout << "ROT13 Caesar Cipher for " << inputChar << " -> P." << endl;
            break;
        case 'D': case 'd':
            cout << "ROT13 Caesar Cipher for " << inputChar << " -> Q." << endl;
            break;
        case 'E': case 'e':
            cout << "ROT13 Caesar Cipher for " << inputChar << " -> R." << endl;
            break;
        case 'F': case 'f':
            cout << "ROT13 Caesar Cipher for " << inputChar << " -> S." << endl;
            break;
        case 'G': case 'g':
            cout << "ROT13 Caesar Cipher for " << inputChar << " -> T." << endl;
            break;
        case 'H': case 'h':
            cout << "ROT13 Caesar Cipher for " << inputChar << " -> U." << endl;
            break;
        case 'I': case 'i':
            cout << "ROT13 Caesar Cipher for " << inputChar << " -> V." << endl;
            break;
        case 'J': case 'j':
            cout << "ROT13 Caesar Cipher for " << inputChar << " -> W." << endl;
            break;
        case 'K': case 'k':
            cout << "ROT13 Caesar Cipher for " << inputChar << " -> X." << endl;
            break;
        case 'L': case 'l':
            cout << "ROT13 Caesar Cipher for " << inputChar << " -> Y." << endl;
            break;
        case 'M': case 'm':
            cout << "ROT13 Caesar Cipher for " << inputChar << " -> Z." << endl;
            break;
        default:
            cout << inputChar << " not found in the ROT13 coding scheme." << endl;
    }
    
    return 0;
}

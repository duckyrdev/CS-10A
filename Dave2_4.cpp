
// Roshni Dave. CS 10A. Sarkar S. Dave2_4.cpp. 

/*
    Word Game Program

    Description:
    This C++ program plays a word game with the user. It collects the user's name, age, city, college, profession, type of animal, and pet's name as input and constructs a story using the provided information.

    */
    
    
#include <iostream>
#include <string>

using namespace std;

int main() {
    

    // Declare variables to store user input
    string name, city, college, profession, animal, petName;
    int age;

    // Collect user input
    cout << "Name: ";
    getline(cin, name);

    cout << "City: ";
    getline(cin, city);

    cout << "Age: ";
    cin >> age;
    cin.ignore(); // Clear the newline character from the buffer

    cout << "College: ";
    getline(cin, college);

    cout << "Profession: ";
    getline(cin, profession);

    cout << "Animal: ";
    getline(cin, animal);

    cout << "Pet Name: ";
    getline(cin, petName);

    // Display the story with user's input
    cout << "\nThere once was a person named " << name << " who lived in " << city << ".\n";
    cout << "At the age of " << age << ", " << name << " went to college at " << college << ".\n";
    cout << name << " graduated and went to work as a " << profession << ".\n";
    cout << "Then, " << name << " adopted a(n) " << animal << " named " << petName << ".\n";
    cout << "They both lived happily ever after!\n";

    return 0;
}

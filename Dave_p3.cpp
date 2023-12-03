// Roshni Dave. CS 10A. Sarkar S. Dave_p3.cpp.

/*
Array Processing Progam: Student Scores

This program manages a dataset of student scores, offering options for input,
display, and analysis. Users can input scores via keyboard or file, view current
scores, find the highest and lowest scores, calculate the average, and get
statistics for individual scores. It provides a user-friendly menu for easy
interaction, ensuring efficient data management and analysis.

 */

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Constants
const int ARRAY_SIZE = 10; // Defines the size of the scores array

// Function Prototypes
void inputScores(int scores[], int size);
void readScoresFromFile(int scores[], int size);
void displayScores(const int scores[], int size);
int findHighestScore(const int scores[], int size);
int findLowestScore(const int scores[], int size);
double calculateAverageScore(const int scores[], int size);
void displaySingleScoreStatistics(const int scores[], int size);

// This program allows the user to manage a dataset of student scores.
// It provides options to input, read, display, and analyze the scores data.

// Function to input scores from keyboard
void inputScores(int scores[], int size) {
  cout << "Enter 10 student scores (range 0 -100)" << endl;
  for (int i = 0; i < size; i++) {
    do {
      cout << "Student #" << (i + 1) << " score: ";
      cin >> scores[i];
      if (scores[i] < 0 || scores[i] > 100) {
        cout << "Invalid score, please retype" << endl;
      }
    } while (scores[i] < 0 || scores[i] > 100);
  }
}

// Function to find the highest score in the array
int findHighestScore(const int scores[], int size) {
  int highest = scores[0];
  for (int i = 1; i < size; ++i) {
    if (scores[i] > highest) {
      highest = scores[i];
    }
  }
  return highest;
}

// Function to find the lowest score in the array
int findLowestScore(const int scores[], int size) {
  int lowest = scores[0];
  for (int i = 1; i < size; ++i) {
    if (scores[i] < lowest) {
      lowest = scores[i];
    }
  }
  return lowest;
}

// Function to calculate the average score of the scores array
double calculateAverageScore(const int scores[], int size) {
  double sum = 0;
  for (int i = 0; i < size; ++i) {
    sum += scores[i];
  }
  return sum / size;
}

// Function to display statistics for a single score
void displaySingleScoreStatistics(const int scores[], int size) {
  int studentNumber;
  cout << "Enter student entry or row # for score statistic (1 -10): ";
  cin >> studentNumber;

  if (studentNumber < 1 || studentNumber > size) {
    cout << "Invalid student number." << endl;
    return;
  }

  int score = scores[studentNumber - 1];
  int higher = 0, lower = 0;

  for (int i = 0; i < size; ++i) {
    if (scores[i] > score)
      higher++;
    else if (scores[i] < score)
      lower++;
  }

  cout << "Student #" << studentNumber << " score: " << score << endl;
  cout << "Score statistics: " << higher << " higher" << endl;
  cout << "Score statistics: " << lower << " lower" << endl;
}

// Function to display all scores
void displayScores(const int scores[], int size) {
  cout << "Displaying 10 student scores" << endl;
  for (int i = 0; i < size; i++) {
    cout << "Student #" << (i + 1) << " score: " << scores[i] << endl;
  }
}

// Function to read scores from a file
void readScoresFromFile(int scores[], int size) {
  string filename;
  cout << "Enter student scores data filename: ";
  cin >> filename;

  ifstream inputFile(filename);
  if (!inputFile) {
    cout << "Error opening the file." << endl;
    return;
  }

  for (int i = 0; i < size && inputFile >> scores[i]; ++i)
    ;

  cout << filename
       << " datafile has successfully opened and 10 scores have been read and "
          "stored."
       << endl;
  inputFile.close();
}

// Main function to execute the program
int main() {
  int scores[ARRAY_SIZE] = {0}; // Initialize array
  int choice;

  do {
    // Display menu
    cout << "STUDENT SCORES DATA SET: 1-D ARRAY PROCESSING MENU OPTIONS"
         << endl;
    cout << "-----------------------------------------------------------"
         << endl;
    cout << "1. New data set: Keyboard input (10 student scores from user)"
         << endl;
    cout << "2. New data set: File data read (10 student scores from a file, "
            "such as scores.txt)"
         << endl;
    cout << "3. Data set: Display current student scores" << endl;
    cout << "4. Data set: Display highest score" << endl;
    cout << "5. Data set: Display lowest score" << endl;
    cout << "6. Data set: Display average score" << endl;
    cout << "7. Data set: Display single score statistics (enter Student entry "
            "number)"
         << endl;
    cout << "8. Quit program" << endl;
    cout << "-----------------------------------------------------------"
         << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    // Process user choice
    switch (choice) {
    case 1:
      inputScores(scores,
                  ARRAY_SIZE); // Call function to input scores from keyboard
      break;
    case 2:
      readScoresFromFile(
          scores, ARRAY_SIZE); // Call function to read scores from a file
      break;
    case 3:
      displayScores(scores, ARRAY_SIZE); // Call function to display all scores
      break;
    case 4:
      cout << "Highest score: " << findHighestScore(scores, ARRAY_SIZE)
           << endl; // Call function to find and display the highest score
      break;
    case 5:
      cout << "Lowest score: " << findLowestScore(scores, ARRAY_SIZE)
           << endl; // Call function to find and display the lowest score
      break;
    case 6:
      cout << "Average score: " << calculateAverageScore(scores, ARRAY_SIZE)
           << endl; // Call function to calculate and display the average score
      break;
    case 7:
      displaySingleScoreStatistics(
          scores,
          ARRAY_SIZE); // Call function to display statistics for a single score
      break;
    case 8:
      cout << "Exiting program..." << endl;
      break;
    default:
      cout << "INVALID CHOICE ...please retype" << endl;
    }
  } while (choice != 8);

  return 0;
}

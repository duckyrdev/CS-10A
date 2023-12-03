// Roshni Dave. CS 10A. Sarkar S. Dave_p3.cpp.

/*

  This C++ program is designed to manage and process movie ratings provided by four reviewers. It stores the ratings in a two-dimensional array where reviewers and movies are indexed for easy access. Users interact with the program through a menu that allows them to display current ratings, compute and show average ratings for each movie, identify the highest rated movies by a particular reviewer, find the lowest rating for a specific movie, enter new ratings, and exit the program. The program includes input validation to ensure that all user inputs are within the expected range, maintaining data integrity and preventing errors.

  */


#include <iostream>
#include <iomanip>
#include <limits> // Include the <limits> header for numeric_limits
using namespace std;

const int NUM_REVIEWERS = 4;  // Number of rows in reviews array
const int NUM_MOVIES = 6;     // Number of columns in reviews array

// Function prototypes
void initialRatings(int ratings[][NUM_MOVIES]);
void getNewRatings(int ratings[][NUM_MOVIES]);
void displayRatings(const int ratings[][NUM_MOVIES]);
void showAverageRatings(const int ratings[][NUM_MOVIES]);
void showReviewersHighestRating(const int ratings[][NUM_MOVIES], int reviewer);
void showMoviesLowestRating(const int ratings[][NUM_MOVIES], int movie);
int getReviewerIndex();
int getMovieIndex();

int main() {
    int ratings[NUM_REVIEWERS][NUM_MOVIES];  // Ratings for reviewers
    int choice;

    // Initialize the array with the initial ratings
    initialRatings(ratings);

    do {
        // Display the menu options
        cout << "---------------------------------------------------" << endl;
        cout << "2-D ARRAY PROCESSING MENU OPTIONS" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << "1. Display current movie ratings" << endl;
        cout << "2. Show the average rating for each movie." << endl;
        cout << "3. Show a reviewers highest rated movie/s. (enter reviewer# 1-4)" << endl;
        cout << "4. Show a movies lowest rating. (enter movie# 100-105)" << endl;
        cout << "5. Enter new ratings (1-5) for movie# 100-105 for four reviewers" << endl;
        cout << "6. Quit program" << endl;
        cout << endl << "Enter your choice: ";
        cin >> choice;

        // Input validation
        if (cin.fail() || choice < 1 || choice > 6) {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore incorrect input
            cout << "INVALID CHOICE ...please retype" << endl;
            continue; // Skip the rest of the loop
        }

        // Process the choice
        switch (choice) {
            case 1:
                displayRatings(ratings);
                break;
            case 2:
                showAverageRatings(ratings);
                break;
            case 3:
                showReviewersHighestRating(ratings, getReviewerIndex());
                break;
            case 4:
                showMoviesLowestRating(ratings, getMovieIndex());
                break;
            case 5:
                getNewRatings(ratings);
                break;
            case 6:
                cout << "Array processing test now concluded. Exiting program ....." << endl;
                break;
            default:
                cout << "INVALID CHOICE ...please retype" << endl;
        }
    } while (choice != 6);

    return 0;
}

// Function definitions below...

// Function to initialize the movie ratings
void initialRatings(int ratings[][NUM_MOVIES]) {
    int initial_ratings[NUM_REVIEWERS][NUM_MOVIES] = {
        {3, 1, 5, 2, 1, 5},
        {4, 2, 1, 4, 2, 4},
        {3, 1, 2, 4, 4, 1},
        {5, 1, 4, 2, 4, 2}
    };

    for (int i = 0; i < NUM_REVIEWERS; i++) {
        for (int j = 0; j < NUM_MOVIES; j++) {
            ratings[i][j] = initial_ratings[i][j];
        }
    }
}

// Function to enter new movie ratings with validation
void getNewRatings(int ratings[][NUM_MOVIES]) {
    for (int i = 0; i < NUM_REVIEWERS; i++) {
        cout << "REVIEWER# " << i + 1 << ":" << endl;
        for (int j = 0; j < NUM_MOVIES; j++) {
            int rating;
            do {
                cout << "Enter rating (1-5) for movie#" << 100 + j << ": ";
                cin >> rating;
                if (cin.fail() || rating < 1 || rating > 5) {
                    cout << "Invalid rating. Please enter a number from 1 to 5." << endl;
                    cin.clear(); // Clear error flags
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore incorrect input
                }
            } while (rating < 1 || rating > 5);
            ratings[i][j] = rating;
        }
    }
}

// Function to display the current movie ratings
void displayRatings(const int ratings[][NUM_MOVIES]) {
    cout << "********************* MOVIE RATINGS ****************" << endl;
    cout << "REVIEWER|  ";
    for (int i = 0; i < NUM_MOVIES; i++) {
        cout << "MV#" << 100 + i << " ";
    }
    cout << endl << "***************************************************" << endl;

    for (int i = 0; i < NUM_REVIEWERS; i++) {
        cout << "  #" << i + 1 << "       ";
        for (int j = 0; j < NUM_MOVIES; j++) {
            cout << ratings[i][j] << "    ";
        }
        cout << endl;
    }
}

// Function to show the average rating for each movie
void showAverageRatings(const int ratings[][NUM_MOVIES]) {
    cout << "Average Rating for each movie:" << endl;
    for (int j = 0; j < NUM_MOVIES; j++) {
        double sum = 0.0;
        for (int i = 0; i < NUM_REVIEWERS; i++) {
            sum += ratings[i][j];
        }
        cout << "Movie#" << 100 + j << ": " << fixed << setprecision(2) << sum / NUM_REVIEWERS << endl;
    }
}

// Function to show a reviewer's highest rated movies and the highest rating
void showReviewersHighestRating(const int ratings[][NUM_MOVIES], int reviewer) {
    cout << "Reviewer#" << reviewer << "'s highest rated movie(s) and rating: ";
    int highest_rating = 0;

    // Find the highest rating for the reviewer
    for (int j = 0; j < NUM_MOVIES; j++) {
        if (ratings[reviewer - 1][j] > highest_rating) {
            highest_rating = ratings[reviewer - 1][j];
        }
    }

    // Display the highest rating
    cout << "Rating: " << highest_rating << endl;

    // Display movies that received the highest rating
    cout << "Movie(s): ";
    for (int j = 0; j < NUM_MOVIES; j++) {
        if (ratings[reviewer - 1][j] == highest_rating) {
            cout << "Movie#" << 100 + j << " ";
        }
    }
    cout << endl;
}

// Function to show a movie's lowest rating and reviewers who gave that rating
void showMoviesLowestRating(const int ratings[][NUM_MOVIES], int movieIndex) {
    cout << "Movie#" << movieIndex + 100 << "'s lowest rating is: ";
    int lowest_rating = 5; // Initialize to the highest possible rating

    // Find the lowest rating for the movie
    for (int i = 0; i < NUM_REVIEWERS; i++) {
        if (ratings[i][movieIndex] < lowest_rating) {
            lowest_rating = ratings[i][movieIndex];
        }
    }

    // Display the lowest rating
    cout << lowest_rating << endl;

    // Display reviewers who gave the lowest rating
    cout << "Given by Reviewer(s): ";
    for (int i = 0; i < NUM_REVIEWERS; i++) {
        if (ratings[i][movieIndex] == lowest_rating) {
            cout << "Reviewer#" << i + 1 << " ";
        }
    }
    cout << endl;
}


// Function to get a valid reviewer index with validation
int getReviewerIndex() {
    int reviewer;
    do {
        cout << "Enter reviewer# (1-4): ";
        cin >> reviewer;
        if (cin.fail() || reviewer < 1 || reviewer > NUM_REVIEWERS) {
            cout << "Invalid reviewer number. Please enter a number from 1 to " << NUM_REVIEWERS << "." << endl;
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore incorrect input
        }
    } while (reviewer < 1 || reviewer > NUM_REVIEWERS);
    return reviewer;
}

// Function to get a valid movie index with validation
int getMovieIndex() {
    int movie;
    do {
        cout << "Enter movie# (100-105): ";
        cin >> movie;
        if (cin.fail() || movie < 100 || movie > 105) {
            cout << "Invalid movie number. Please enter a number from 100 to 105." << endl;
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore incorrect input
        }
    } while (movie < 100 || movie > 105);
    return movie - 100; // Adjust for 0-based index
}

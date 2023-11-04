// Roshni Dave. CS 10A. Sarkar S. Dave4.cpp.

/*

Program description:
Phase I: The program collects the ages of moviegoers in five age categories.
Users input attendee ages until they enter a negative number, at which point the
program reports the number of attendees in each age group.

Phase II: Building on the first phaese, this phase also calculates and displays
additional statistics, including the average age of attendees, the age of the
youngest person, and the age of the oldest person in attendance.

Phase III: In addition to the functionality from Phase II, this phase extends
the program to gather data on concession stand purchases made by each attendee.
Users can to select from a list of seven concession items. Finally, program
provides a summary of concession sales for each item along with demographic
statistics.

*/


#include <climits>
#include <iostream>

using namespace std;

int main() {
  int age, choice;
  int ageCounts[5] = {0};
  int totalAges = 0;
  int totalAttendees =
      0; // Initialize a variable to keep track of the total number of attendees
  int youngest = INT_MAX;
  int oldest = INT_MIN;
  int concessionCounts[7] = {0};

  cout << "===========================" << endl;
  cout << "THEATER STATS PROGRAM" << endl;
  cout << "===========================" << endl;

  cout << "Movie theater snacks available for purchase" << endl;
  cout << "==========================================" << endl;
  cout << "1 - Soft Drink (such as Coca Cola, ICCEE, Mineral Water etc...)"
       << endl;
  cout << "2 - Popcorn" << endl;
  cout << "3 - Nachos" << endl;
  cout << "4 - Soft drink & Popcorn" << endl;
  cout << "5 - Soft drink & Nachos" << endl;
  cout << "6 - Organic and Gluten-free snacks" << endl;
  cout << "7 - None" << endl;
  cout << "==========================================" << endl;

  while (true) {
    cout << "Enter age of attendee (-1 to quit): ";
    cin >> age;

    if (age == -1) {
      break;
    }

    if (age < 0) {
      cout << "Invalid age, please enter a valid age." << endl;
      continue;
    }

    totalAttendees++; // Increment the total number of attendees
    totalAges += age; // Increment the sum of ages

    // Update ageCounts based on age group
    if (age <= 18) {
      ageCounts[0]++;
    } else if (age >= 19 && age <= 30) {
      ageCounts[1]++;
    } else if (age >= 31 && age <= 40) {
      ageCounts[2]++;
    } else if (age >= 41 && age <= 60) {
      ageCounts[3]++;
    } else {
      ageCounts[4]++;
    }

    // Update youngest and oldest ages
    if (age < youngest) {
      youngest = age;
    }
    if (age > oldest) {
      oldest = age;
    }

    while (true) {
      cout << "Movie theater snack purchased. (Select items 1 - 7): ";
      cin >> choice;

      if (choice >= 1 && choice <= 7) {
        concessionCounts[choice - 1]++;
        break;
      } else {
        cout << "Invalid selection, please choose from 1 - 7" << endl;
      }
    }
    cout << "--------------------------" << endl;
  }

  cout << "==================================" << endl;
  cout << "  THEATER STATS PROGRAM RESULTS" << endl;
  cout << "==================================" << endl;

  cout << "age 0  to 18:    " << ageCounts[0] << endl;
  cout << "age 19 to 30:    " << ageCounts[1] << endl;
  cout << "age 31 to 40:    " << ageCounts[2] << endl;
  cout << "age 41 to 60:    " << ageCounts[3] << endl;
  cout << "over 60:         " << ageCounts[4] << endl;

  cout << "The average age was "
       << (totalAttendees > 0 ? static_cast<double>(totalAges) / totalAttendees
                              : 0)
       << endl;
  cout << "The youngest person in attendance was " << youngest << endl;
  cout << "The oldest person in attendance was " << oldest << endl;

  cout << "Theater Concession Stand sales" << endl;
  cout << "==================================" << endl;
  cout << "Soft Drink (such as Coca Cola, ICCEE, Mineral Water etc.): "
       << concessionCounts[0] << endl;
  cout << "Popcorn: " << concessionCounts[1] << endl;
  cout << "Nachos: " << concessionCounts[2] << endl;
  cout << "Soft drink & Popcorn: " << concessionCounts[3] << endl;
  cout << "Soft drink & Nachos: " << concessionCounts[4] << endl;
  cout << "Organic and Gluten-free snacks: " << concessionCounts[5] << endl;
  cout << "None: " << concessionCounts[6] << endl;

  return 0;
}

// Roshni Dave. CS 10A. Sarkar S. Dave_p1.cpp. 

/*
  This program takes user input for rocket dimensionsm etc, and uses them to build a drawing of a rocket with a defined number of sections, a fitting cone, and a changeable height and width.

*/

#include <iostream>
using namespace std;

// program interface in main
void programInfo();
void getRocketSpecs(int &moduleWidth, int &moduleHeight, int &numModules, char &moduleSpace);
void drawRocket(int moduleWidth, int moduleHeight, int numModules, char moduleSpace);

// rocket module build
void dockRocketModules(int moduleWidth, int moduleHeight, int numModules, char moduleSpace);
void buildRocketModuleTypes(int moduleWidth, int moduleHeight, char moduleSpace);
void drawFilledRocketModule(int moduleWidth, int moduleHeight);
void drawEmptyRocketModule(int moduleWidth, int moduleHeight);

// rocket cones build
void drawTwoRocketHollowConeTypes(int moduleWidth);
void drawTwoRocketFilledConeTypes(int moduleWidth);
void drawRocketHollowConeTypes(int moduleWidth);
void drawRocketFilledConeTypes(int moduleWidth);
void drawRocketBoosters(int moduleWidth);
void rocketBoosterSpacer(int spacer);

int main() {
    int moduleWidth;    // the width of each rocket module
    int moduleHeight;   // the height of each rocket module
    int numModules;     // the number of modules docked in the rocket
    char moduleSpace;   // empty of filled modules
    char choice = 'N';

    programInfo();

    do {
        getRocketSpecs(moduleWidth, moduleHeight, numModules, moduleSpace);
        drawRocket(moduleWidth, moduleHeight, numModules, moduleSpace);

        cout << "\n\n---------------------------------------------------------" << endl;
        cout << " Try the ROCKET BUILD pattern generating algorithms again?" << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "Type 'Y' for yes or 'N' for no: ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    cout << "\nNow exiting the ROCKET BUILD program ...." << endl;

    return 0;
}

void programInfo() {
    cout << "Welcome to the Rocket Build Program!\n";
    cout << "You'll be prompted to input various specifications for your rocket.\n";
    cout << "Based on your input, a representation of the rocket will be displayed.\n";
    cout << "Let's get started!\n";
}

void getRocketSpecs(int &moduleWidth, int &moduleHeight, int &numModules, char &moduleSpace) {
    do {
        cout << "Enter module width (10-15): ";
        cin >> moduleWidth;
        if (moduleWidth < 10 || moduleWidth > 15) {
            cout << "Invalid input! Width should be between 10 and 15 inclusive.\n";
        }
    } while (moduleWidth < 10 || moduleWidth > 15);

    do {
        cout << "Enter module height (5-10): ";
        cin >> moduleHeight;
        if (moduleHeight < 5 || moduleHeight > 10) {
            cout << "Invalid input! Height should be between 5 and 10 inclusive.\n";
        }
    } while (moduleHeight < 5 || moduleHeight > 10);

    do {
        cout << "Enter number of modules (2-5): ";
        cin >> numModules;
        if (numModules < 2 || numModules > 5) {
            cout << "Invalid input! Number of modules should be between 2 and 5 inclusive.\n";
        }
    } while (numModules < 2 || numModules > 5);

    do {
        cout << "Enter 'E' for Empty or 'F' for Filled rocket module: ";
        cin >> moduleSpace;
        moduleSpace = toupper(moduleSpace); // Convert to uppercase for consistency
        if (moduleSpace != 'E' && moduleSpace != 'F') {
            cout << "Invalid input! Please enter 'E' for Empty or 'F' for Filled.\n";
        }
    } while (moduleSpace != 'E' && moduleSpace != 'F');
}


void dockRocketModules(int moduleWidth, int moduleHeight, int numModules, char moduleSpace) {
    // Decide the type of cone based on the width of the module and whether the module is filled or empty
    if (moduleWidth % 2 == 0) {  // even width
        if (moduleSpace == 'E' || moduleSpace == 'e') {
            drawTwoRocketFilledConeTypes(moduleWidth);
        } else {
            drawTwoRocketHollowConeTypes(moduleWidth);
        }
    } else {  // odd width
        if (moduleSpace == 'E' || moduleSpace == 'e') {
            drawRocketFilledConeTypes(moduleWidth);
        } else {
            drawRocketHollowConeTypes(moduleWidth);
        }
    }

    // Draw the modules based on user choice
    for (int i = 0; i < numModules; i++) {
        buildRocketModuleTypes(moduleWidth, moduleHeight, moduleSpace);
    }
}

void buildRocketModuleTypes(int moduleWidth, int moduleHeight, char moduleSpace) {
    if (moduleSpace == 'E' || moduleSpace == 'e') {
        drawEmptyRocketModule(moduleWidth, moduleHeight);
    } else {
        drawFilledRocketModule(moduleWidth, moduleHeight);
    }
}

void drawFilledRocketModule(int moduleWidth, int moduleHeight) {
    for (int i = 0; i < moduleHeight; i++) {
        for (int j = 0; j < moduleWidth; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void drawEmptyRocketModule(int moduleWidth, int moduleHeight) {
    for (int i = 0; i < moduleHeight; i++) {
        if (i == 0 || i == moduleHeight - 1) {
            for (int j = 0; j < moduleWidth; j++) {
                cout << "*";
            }
        } else {
            cout << "*";
            for (int j = 0; j < moduleWidth - 2; j++) {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }
}

void drawRocketFilledConeTypes(int moduleWidth) {
    int space = moduleWidth / 2;
    for (int i = 0; i < moduleWidth / 2 + 1; i++) {
        for (int j = 0; j < space; j++) {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        }
        cout << endl;
        space--;
    }
}

// Draw hollow cone for odd module widths
void drawRocketHollowConeTypes(int moduleWidth) {
    int space = moduleWidth / 2;
    for (int i = 0; i < moduleWidth / 2 + 1; i++) {
        for (int j = 0; j < space; j++) {
            cout << " ";
        }
        if (i == 0 || i == moduleWidth / 2) {
            cout << "*";
        } else {
            cout << "*";
            for (int j = 0; j < 2 * i - 1; j++) {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
        space--;
    }
}


void drawTwoRocketFilledConeTypes(int moduleWidth) {
    int space = moduleWidth / 2 - 1;
    for (int i = 0; i < moduleWidth / 2; i++) {
        for (int j = 0; j < space; j++) {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 2; j++) {
            cout << "*";
        }
        cout << endl;
        space--;
    }
}

// Draw hollow cone for even module widths
void drawTwoRocketHollowConeTypes(int moduleWidth) {
    int space = moduleWidth / 2 - 1;
    for (int i = 0; i < moduleWidth / 2; i++) {
        for (int j = 0; j < space; j++) {
            cout << " ";
        }
        if (i == 0) {
            cout << "**";
        } else {
            cout << "*";
            for (int j = 0; j < 2 * i; j++) {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
        space--;
    }
}

void drawRocket(int moduleWidth, int moduleHeight, int numModules, char moduleSpace) {
    dockRocketModules(moduleWidth, moduleHeight, numModules, moduleSpace);
    drawRocketBoosters(moduleWidth);
}

void drawRocketBoosters(int moduleWidth) {
    int spacer = 0;

    switch(moduleWidth) {
        case 12:
            spacer=11;
            break;
        case 13:
            spacer=11;
            break;
        case 14:
            spacer=12;
            break;
        case 15:
            spacer=12;
            break;
    }

    rocketBoosterSpacer(spacer);
    cout << "  *    *\n";
    rocketBoosterSpacer(spacer);
    cout << " ***  ***\n";
    rocketBoosterSpacer(spacer);
    cout << "*   **   *\n";
}

void rocketBoosterSpacer(int spacer) {
    for (int spaceCount = 10; spaceCount < spacer; spaceCount++) {
        cout << " ";
    }
}

#include <iostream>


//name: Roshni Dave
// assignment 1-3 

int main() {
    const double townMilesPerGallon = 21.5;
    const double highwayMilesPerGallon = 26.8;
    const double tankCapacity = 20.0;

    double townDistance = tankCapacity * townMilesPerGallon;
    double highwayDistance = tankCapacity * highwayMilesPerGallon;

    std::cout << "Town: " << townDistance << std::endl;
    std::cout << "Highway: " << highwayDistance << std::endl;

    system("pause"); // Pause to see the output
    return 0;
}

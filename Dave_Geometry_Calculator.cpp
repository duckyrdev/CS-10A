// Roshni Dave. CS 10A. Sarkar S. Dave_Geometry_Calculator.cpp


//The "Geometry Calculator" program presents a menu to the user with four options: calculating the area of a circle, rectangle, triangle, or quitting the program. It employs a switch statement to perform the selected geometric calculations based on user input, taking into account input validation to ensure that only valid data is processed. It then displays the calculated areas with appropriate formatting and continues to prompt the user for choices until they decide to quit the program.


#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    const double PI = 3.14159;
    int choice;

    do {
        std::cout << "Geometry Calculator\n";
        std::cout << "1. Calculate the Area of a Circle\n";
        std::cout << "2. Calculate the Area of a Rectangle\n";
        std::cout << "3. Calculate the Area of a Triangle\n";
        std::cout << "4. Quit\n";
        std::cout << "Enter your choice (1 - 4): ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                double radius, area;
                std::cout << "Enter the radius of the circle: ";
                std::cin >> radius;
                if (radius > 0) {
                    area = PI * pow(radius, 2);
                    std::cout << "The area of the circle is: " << std::fixed << std::setprecision(2) << area << std::endl;
                } else {
                    std::cout << "Invalid input. Please enter a positive radius.\n";
                }
                break;
            }
            case 2: {
                double length, width, area;
                std::cout << "Enter the length of the rectangle: ";
                std::cin >> length;
                std::cout << "Enter the width of the rectangle: ";
                std::cin >> width;
                if (length > 0 && width > 0) {
                    area = length * width;
                    std::cout << "The area of the rectangle is: " << area << std::endl;
                } else {
                    std::cout << "Invalid input. Please enter positive length and width.\n";
                }
                break;
            }
            case 3: {
                double base, height, area;
                std::cout << "Enter the base of the triangle: ";
                std::cin >> base;
                std::cout << "Enter the height of the triangle: ";
                std::cin >> height;
                if (base > 0 && height > 0) {
                    area = 0.5 * base * height;
                    std::cout << "The area of the triangle is: " << area << std::endl;
                } else {
                    std::cout << "Invalid input. Please enter positive base and height.\n";
                }
                break;
            }
            case 4:
                std::cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}

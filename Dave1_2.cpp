#include <iostream>
#include <iomanip> // decimals

// name: Roshni Dave
// assignment 1-2

int main() {
    double item1 = 12.95;
    double item2 = 24.95;
    double item3 = 6.95;
    double item4 = 14.95;
    double item5 = 3.95;

    double subtotal = item1 + item2 + item3 + item4 + item5;
    double salesTaxRate = 0.06; // 6%
    double salesTax = subtotal * salesTaxRate;
    double total = subtotal + salesTax;

    std::cout << std::fixed << std::setprecision(2); // 2 places

    std::cout << "Item 1: $" << item1 << std::endl;
    std::cout << "Item 2: $" << item2 << std::endl;
    std::cout << "Item 3: $" << item3 << std::endl;
    std::cout << "Item 4: $" << item4 << std::endl;
    std::cout << "Item 5: $" << item5 << std::endl;

    std::cout << "Subtotal: $" << subtotal << std::endl;
    std::cout << "Sales tax: $" << salesTax << std::endl;
    std::cout << "Total: $" << total << std::endl;

    return 0;
}

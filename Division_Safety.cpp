#include <iostream>
#include <stdexcept>

void divide(int a, int b) {
    try {
        if (b == 0) {
            throw std::logic_error("Division by zero.");
        }
        int result = a / b;
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        // Additional error handling logic can be added here
    }
}

int main() {
    // Example usage of trap in a function
    divide(10, 2);
    divide(5, 0);

    return 0;
}

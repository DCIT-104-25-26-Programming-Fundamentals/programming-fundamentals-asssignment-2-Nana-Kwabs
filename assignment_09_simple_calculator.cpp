// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double add(double a, double b) {
    return a + b;
}
double subtract(double a, double b) {
    return a - b;
}
double multiply(double a, double b) {
    return a * b;
}
double divide(double a, double b) {
    if (b == 0) {
        throw invalid_argument("Error: Cannot divide by zero.");
    }
    return a / b;
}
double calculateModulus(double a, double b) {
    if (b == 0) {
        throw invalid_argument("Error: Cannot calculate modulus with zero.");
    }
    return fmod(a, b);
}
double power(double a, double b) {
    return pow(a, b);
}  
void displayMenu() {
    cout << "============================" << endl;
    cout << "      SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
    cout << "Select an operation (1-7): ";
}
int main() {
    int choice;
    double num1, num2, result;

    do {
        displayMenu();
        cin >> choice;

        if (choice >= 1 && choice <= 6) {
            cout << "Enter first number : ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;
        }

        try {
            switch (choice) {
                case 1:
                    result = add(num1, num2);
                    cout << fixed << setprecision(2) << "Result: " << num1 << " + " << num2 << " = " << result << endl;
                    break;
                case 2:
                    result = subtract(num1, num2);
                    cout << fixed << setprecision(2) << "Result: " << num1 << " - " << num2 << " = " << result << endl;
                    break;
                case 3:
                    result = multiply(num1, num2);
                    cout << fixed << setprecision(2) << "Result: " << num1 << " * " << num2 << " = " << result << endl;
                    break;
                case 4:
                    result = divide(num1, num2);
                    cout << fixed << setprecision(2) << "Result: " << num1 << " / " << num2 << " = " << result << endl;
                    break;
                case 5:
                    result = calculateModulus(num1, num2);
                    cout << fixed << setprecision(2) << "Result: " << num1 << " % " << num2 << " = " << result << endl;
                    break;
                case 6:
                    result = power(num1, num2);
                    cout << fixed << setprecision(2) << "Result: " << num1 << " ^ " << num2 << " = " << result << endl;
                    break;
                case 7:
                    cout << "Goodbye!" << endl;
                    break;
                default:
                    cout << "Error: Invalid choice. Please select a number between 1 and 7." << endl;
            }
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }

    } while (choice != 7);

    return 0;
}
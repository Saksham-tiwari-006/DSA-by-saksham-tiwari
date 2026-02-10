#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
using namespace std;

class Calculator {
public:
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
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
        return a / b;
    }
    
    double power(double base, double exponent) {
        return pow(base, exponent);
    }
    
    double squareRoot(double num) {
        if (num < 0) {
            cout << "Error: Cannot calculate square root of negative number!" << endl;
            return 0;
        }
        return sqrt(num);
    }
    
    double cubeRoot(double num) {
        return cbrt(num);
    }
    
    double modulo(int a, int b) {
        if (b == 0) {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
        return a % b;
    }
    
    double absolute(double num) {
        return abs(num);
    }
    
    double sine(double angle) {
        return sin(angle * M_PI / 180.0);
    }
    
    double cosine(double angle) {
        return cos(angle * M_PI / 180.0);
    }
    
    double tangent(double angle) {
        return tan(angle * M_PI / 180.0);
    }
    
    double logarithm(double num) {
        if (num <= 0) {
            cout << "Error: Logarithm of non-positive number!" << endl;
            return 0;
        }
        return log10(num);
    }
    
    double naturalLog(double num) {
        if (num <= 0) {
            cout << "Error: Logarithm of non-positive number!" << endl;
            return 0;
        }
        return log(num);
    }
    
    double exponential(double num) {
        return exp(num);
    }
    
    double factorial(int n) {
        if (n < 0) {
            cout << "Error: Factorial of negative number!" << endl;
            return 0;
        }
        double result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }
    
    double percentage(double num, double percent) {
        return (num * percent) / 100.0;
    }
    
    double floor_value(double num) {
        return floor(num);
    }
    
    double ceil_value(double num) {
        return ceil(num);
    }
    
    double round_value(double num) {
        return round(num);
    }
    
    double gcd(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    double lcm(int a, int b) {
        return abs(a * b) / gcd(a, b);
    }
    
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
};

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void displayMenu() {
    cout << "\n========== ADVANCED CALCULATOR ==========" << endl;
    cout << "1.  Addition (+)" << endl;
    cout << "2.  Subtraction (-)" << endl;
    cout << "3.  Multiplication (*)" << endl;
    cout << "4.  Division (/)" << endl;
    cout << "5.  Power (a^b)" << endl;
    cout << "6.  Square Root (√)" << endl;
    cout << "7.  Cube Root (∛)" << endl;
    cout << "8.  Modulo (%)" << endl;
    cout << "9.  Absolute Value (|x|)" << endl;
    cout << "10. Sine (sin)" << endl;
    cout << "11. Cosine (cos)" << endl;
    cout << "12. Tangent (tan)" << endl;
    cout << "13. Logarithm Base 10 (log)" << endl;
    cout << "14. Natural Logarithm (ln)" << endl;
    cout << "15. Exponential (e^x)" << endl;
    cout << "16. Factorial (n!)" << endl;
    cout << "17. Percentage (%)" << endl;
    cout << "18. Floor Value" << endl;
    cout << "19. Ceiling Value" << endl;
    cout << "20. Round Value" << endl;
    cout << "21. GCD (Greatest Common Divisor)" << endl;
    cout << "22. LCM (Least Common Multiple)" << endl;
    cout << "23. Check Prime Number" << endl;
    cout << "0.  Exit" << endl;
    cout << "=========================================" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Calculator calc;
    int choice;
    double num1, num2, result;
    
    cout << fixed << setprecision(4);
    
    while (true) {
        displayMenu();
        cin >> choice;
        
        if (cin.fail()) {
            cout << "Invalid input! Please enter a number." << endl;
            clearInput();
            continue;
        }
        
        if (choice == 0) {
            cout << "Thank you for using the calculator. Goodbye!" << endl;
            break;
        }
        
        switch (choice) {
            case 1:
                cout << "Enter first number: ";
                cin >> num1;
                cout << "Enter second number: ";
                cin >> num2;
                result = calc.add(num1, num2);
                cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
                break;
                
            case 2:
                cout << "Enter first number: ";
                cin >> num1;
                cout << "Enter second number: ";
                cin >> num2;
                result = calc.subtract(num1, num2);
                cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
                break;
                
            case 3:
                cout << "Enter first number: ";
                cin >> num1;
                cout << "Enter second number: ";
                cin >> num2;
                result = calc.multiply(num1, num2);
                cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
                break;
                
            case 4:
                cout << "Enter numerator: ";
                cin >> num1;
                cout << "Enter denominator: ";
                cin >> num2;
                result = calc.divide(num1, num2);
                if (num2 != 0)
                    cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
                break;
                
            case 5:
                cout << "Enter base: ";
                cin >> num1;
                cout << "Enter exponent: ";
                cin >> num2;
                result = calc.power(num1, num2);
                cout << "Result: " << num1 << " ^ " << num2 << " = " << result << endl;
                break;
                
            case 6:
                cout << "Enter number: ";
                cin >> num1;
                result = calc.squareRoot(num1);
                if (num1 >= 0)
                    cout << "Result: √" << num1 << " = " << result << endl;
                break;
                
            case 7:
                cout << "Enter number: ";
                cin >> num1;
                result = calc.cubeRoot(num1);
                cout << "Result: ∛" << num1 << " = " << result << endl;
                break;
                
            case 8:
                cout << "Enter first number: ";
                cin >> num1;
                cout << "Enter second number: ";
                cin >> num2;
                result = calc.modulo((int)num1, (int)num2);
                if ((int)num2 != 0)
                    cout << "Result: " << (int)num1 << " % " << (int)num2 << " = " << (int)result << endl;
                break;
                
            case 9:
                cout << "Enter number: ";
                cin >> num1;
                result = calc.absolute(num1);
                cout << "Result: |" << num1 << "| = " << result << endl;
                break;
                
            case 10:
                cout << "Enter angle in degrees: ";
                cin >> num1;
                result = calc.sine(num1);
                cout << "Result: sin(" << num1 << "°) = " << result << endl;
                break;
                
            case 11:
                cout << "Enter angle in degrees: ";
                cin >> num1;
                result = calc.cosine(num1);
                cout << "Result: cos(" << num1 << "°) = " << result << endl;
                break;
                
            case 12:
                cout << "Enter angle in degrees: ";
                cin >> num1;
                result = calc.tangent(num1);
                cout << "Result: tan(" << num1 << "°) = " << result << endl;
                break;
                
            case 13:
                cout << "Enter number: ";
                cin >> num1;
                result = calc.logarithm(num1);
                if (num1 > 0)
                    cout << "Result: log10(" << num1 << ") = " << result << endl;
                break;
                
            case 14:
                cout << "Enter number: ";
                cin >> num1;
                result = calc.naturalLog(num1);
                if (num1 > 0)
                    cout << "Result: ln(" << num1 << ") = " << result << endl;
                break;
                
            case 15:
                cout << "Enter number: ";
                cin >> num1;
                result = calc.exponential(num1);
                cout << "Result: e^" << num1 << " = " << result << endl;
                break;
                
            case 16:
                cout << "Enter number: ";
                cin >> num1;
                result = calc.factorial((int)num1);
                if ((int)num1 >= 0)
                    cout << "Result: " << (int)num1 << "! = " << result << endl;
                break;
                
            case 17:
                cout << "Enter number: ";
                cin >> num1;
                cout << "Enter percentage: ";
                cin >> num2;
                result = calc.percentage(num1, num2);
                cout << "Result: " << num2 << "% of " << num1 << " = " << result << endl;
                break;
                
            case 18:
                cout << "Enter number: ";
                cin >> num1;
                result = calc.floor_value(num1);
                cout << "Result: floor(" << num1 << ") = " << result << endl;
                break;
                
            case 19:
                cout << "Enter number: ";
                cin >> num1;
                result = calc.ceil_value(num1);
                cout << "Result: ceil(" << num1 << ") = " << result << endl;
                break;
                
            case 20:
                cout << "Enter number: ";
                cin >> num1;
                result = calc.round_value(num1);
                cout << "Result: round(" << num1 << ") = " << result << endl;
                break;
                
            case 21:
                cout << "Enter first number: ";
                cin >> num1;
                cout << "Enter second number: ";
                cin >> num2;
                result = calc.gcd((int)num1, (int)num2);
                cout << "Result: GCD(" << (int)num1 << ", " << (int)num2 << ") = " << (int)result << endl;
                break;
                
            case 22:
                cout << "Enter first number: ";
                cin >> num1;
                cout << "Enter second number: ";
                cin >> num2;
                result = calc.lcm((int)num1, (int)num2);
                cout << "Result: LCM(" << (int)num1 << ", " << (int)num2 << ") = " << (int)result << endl;
                break;
                
            case 23:
                cout << "Enter number: ";
                cin >> num1;
                if (calc.isPrime((int)num1))
                    cout << (int)num1 << " is a prime number." << endl;
                else
                    cout << (int)num1 << " is not a prime number." << endl;
                break;
                
            default:
                cout << "Invalid choice! Please select a valid option." << endl;
        }
        
        cout << "\nPress Enter to continue...";
        clearInput();
        cin.get();
    }
    
    return 0;
}

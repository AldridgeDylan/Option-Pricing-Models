#include <iostream>
#include <string>
using namespace std;

#define NEWLINE '\n' // Requires no run-time memory (generally advised not to use)
const double PI = 3.14;

inline void pointerArithmetic(int, int, double&);
int adder(string name, int age);

int main() {
    int a = 50, age, adderResult;
    decltype(a) b(30);
    double result;
    string myString {"Computation Complete"};
    string secondString = R"(&%$(string with \backslash)&%$)";
    string name;

    pointerArithmetic(a, b, result);
    cout << result << NEWLINE << myString << "\n" << secondString << endl;

    int x, y = 5 + ( x = 5 );
    cout << "x:" << ++x << " y:" << (y *= y) << endl;

    bool boolean = ( 7 == 7 ? true : false );
    if ( boolean ){
        cout << "The following is a boolean test (1 if true and 0 if false): " << boolean << endl;
    }
  
    cout << "Please enter your name: ";
    getline(cin, name);
    cout << "Please enter your age: ";
    cin >> age;

    adderResult = adder(name, age); // Default age parameter means that it isn't required as a function argument

    cout << "The total of your numbers is: " << adderResult << endl;

    return 0;
}

// Passing arguments by reference is more efficient for complex data types
// If arguments passed by reference should not be altered, they should be marked as const
inline void pointerArithmetic(int a, int b, double& result) {
    result = (a + b)/PI;
}

int adder(string name, int age=17) {
    int num1, num2;

    if (age < 18) {
        cout << "You must be over 18 to use this calculator" << endl;
        return 1; // This needs to be changed to throw an error
    }

    cout << "Welcome to the adder " << name << "!\nPlease enter the numbers you want added:\n";
    cin >> num1 >> num2;

    return num1 + num2;
}

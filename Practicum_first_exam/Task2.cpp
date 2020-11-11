#include <iostream>

using namespace std;

//Task2
int main() {
    int number, secondDigit, thirdDigit;
    bool isTrue = true;
    cout << "Enter a number (NOTE: it has to be at least 3 digit long): ";
    cin >> number;

    // Validation
    if (number / 1000 == 0 || number < 0) {
        cout << "Invalid number!" << endl;
    }
    else {
        // Going trough every digit while the number itself has 3 digits
        while (number / 1000 != 0) {
            secondDigit = (number / 10) % 10;
            thirdDigit = (number / 100) % 10;
            // Checking if the third digit = first digit + second digit
            if (thirdDigit != (secondDigit + (number % 10))) {
                isTrue = false;
                break;
            }

            number /= 10;
        };
        //Displaying the result
        if (isTrue) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

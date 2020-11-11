#include <iostream>

using namespace std;

//Task1
int main() {
    int number, interestingNum[100];
    bool isInteresting = true;
    cout << "Enter a number (between 1 and 99) to set the the amount of numbers you want to enter: ";
    cin >> number;

    // Validation
    if (number < 1 || number > 99) {
        cout << "Invalid number!" << endl;
    }
    else {
        // Entering the numbers which could be 'interesting'
        cout << "Enter the numbers you want to check, separated with 'Enter': " << endl;
        for (size_t i = 0; i < number; i++) {
            cin >> interestingNum[i];
        }
        for (size_t i = 0; i < number; i++) {
            // Going trough every digit of the number in order to check if it is 'interesting'
            while (interestingNum[i] / 10 != 0) {
                if ((interestingNum[i] / 10) % 10 > interestingNum[i] % 10) {
                    isInteresting = false;
                    break;
                }
                interestingNum[i] /= 10;
            };
            // Displaying the result
            if (isInteresting) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
            // Setting 'isInteresting' again to true
            isInteresting = true;
        }
    }

    return 0;
}

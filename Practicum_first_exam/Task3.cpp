#include <iostream>

using namespace std;

//Task 3
int main() {
    int number, evenSum = 0, oddSum = 0;
    char ch[100] = {0};
    cout << "Enter the length of your array of chars (number between 1 and 99): ";
    cin >> number;

    // Validation
    if (number < 1 || number > 99) {
        cout << "Invalid number!" << endl;
    }
    else {
        // Filling the array of chars
        cout << "Enter all chars" << endl;
        for (size_t i = 0; i < number; i++) {
            cin >> ch[i];
        }
        // Going trough every element of the array in order to find out if it is even or odd
        // and add it to the appropriate sum.
        // NOTE: The loop(array indexes also) starts from 0. So all even indexes are odd and reverse.
        for (size_t i = 0; i < number; i++) {
            if (i % 2 == 0) {
                oddSum += ch[i];
            } else {
                evenSum += ch[i];
            }
        }
        // Displaying the results.
        cout << "Odd sum is = " << oddSum << endl;
        cout << "Even sum is = " << evenSum << endl;
        if (oddSum > evenSum) {
            cout << "Odd sum is greater than even sum." << endl;
        } else if (evenSum > oddSum) {
            cout << "Even sum is greater than odd sum." << endl;
        } else {
            cout << "Odd sum is equal than even sum." << endl;
        }
    }
    return 0;
}

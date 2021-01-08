#include <iostream>

using std::cin;
using std::cout;
using std::endl;

static int counter = 0;
bool doesConsist (const int arr1[], const int arr2[], const int arr1Length, const int arr2Length) {
    for (int i = 0; i < arr2Length; ++i) {
        if (*arr1 == arr2[i] || arr1Length == 0) {
            counter++;
            break;
        }
    }
    if (counter == 0) {
        return false;
    }
    if (arr1Length == 0) {
        return true;
    }
    counter = 0;
    return doesConsist((arr1 + 1), arr2, arr1Length - 1, arr2Length);
}
void validation (const int arr1[], const int arr2[], const int arr1length, const int arr2Length) {
    for (int i = 0; i < arr1length; ++i) {
        for (int j = 0; j < arr1length; ++j) {
            if (i == j) {
                continue;
            }
            if (arr1[i] == arr1[j]) {
                cout << "Invalid data" << endl;
                return;
            }
        }
    }
    bool answer = doesConsist(arr1, arr2, arr1length, arr2Length);
    if (answer) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    int arr1[5] = {2, 1, 5, 4, 6};
    int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 18, 7, 11};
    validation(arr1, arr2, 5, 10);

    return 0;
}

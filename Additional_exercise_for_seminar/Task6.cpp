#include <iostream>

using std::cin;
using std::cout;
using std::endl;

double recursiveMultiplication (const double arr[], int length) {
    if (length == 0) {
        return 1;
    }
    if (*arr < *(arr - 1) && *arr >= 0) {
        return *arr * recursiveMultiplication(arr + 1, length - 1);
    }
    return recursiveMultiplication(arr + 1, length - 1);
}

int main() {
    double arr[8] = {2.1, 3, 9.9, 3, 1, -1, 14.5, 7};
    cout << recursiveMultiplication(arr, 8) << endl;
    return 0;
}

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool isZigZak (const int arr[], const int size) {
    for (int i = 0; i < size - 1; ++i) {
        if (i % 2 == 0) {
            if (arr[i] >= arr[i+1]) {
                return false;
            }
        }
        else {
            if (arr[i] <= arr[i + 1]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int arr[6] = {1, 3, 2, 4, 3, 7};
    cout << std::boolalpha << isZigZak(arr, 6) << endl;
    return 0;
}

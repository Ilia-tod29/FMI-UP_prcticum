#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const int MAX_SIZE = 4000;
void print (const int* arr, const int length) {
    for (int i = 1; i < length; ++i) {
        cout << arr[i] << ", ";
    }
    cout << endl;
}
void remove (int* arr, int position, int length) {
    for (int i = position; i < length; ++i) {
        arr[i] = arr[i + 1];
    }
}
int sieveOfEratosthenes (int* arr, int length) {
    for (int i = 1; i < length; ++i) {
        for (int j = i + i; j < length; ++j) {
            if (arr[j] % arr[i] == 0) {
                remove(arr, j, length);
                length--;
            }
        }
    }
    print(arr, length);
}
void fillArr (int* arr, int length) {
    for (int i = 0; i < length; ++i) {
        arr[i] = i + 1;
    }
}
int main() {
    int arr[MAX_SIZE], n;
    cout << "Enter the number up to which you want to display all the prime numbers: ";
    cin >> n;
    fillArr(arr, n);
    sieveOfEratosthenes(arr, n);
    return 0;
}

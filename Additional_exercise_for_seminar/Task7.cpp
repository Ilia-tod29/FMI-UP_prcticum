#include <iostream>

using std::cin;
using std::cout;
using std::endl;

char letterSwap (char* str, int* arr) {
    if (*str == '\0') {
        return *str;
    }
    if (*str <= 'z' && *str >= 'a') {
        *str += *arr;
        if (*str > 'z') {
            *str -= 26;
        }
    }
    else if (*str < 'Z' && *str > 'A') {
        *str += *arr;
        if (*str > 'Z') {
            *str -= 26;
        }
    }
    else {
        cout << "Invalid data!" << endl;
        return 0;
    }
    return letterSwap(str + 1, arr + 1);
}

int main() {
    char str[11] = "LoremIpsum";
    int arr[10] = {1, 0, 2, 5, 6, 2, 11, 9, 3, 3};
    letterSwap(str, arr);
    cout << str << endl;
    return 0;
}
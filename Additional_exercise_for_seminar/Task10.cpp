#include <iostream>

using std::cin;
using std::cout;
using std::endl;

char letterToNumber (char* str, const int* arr) {
    if (*str == '\0') {
        return *str;
    }
    if (*str <= 'z' && *str >= 'a') {
        *str = arr[(int)*str - 97] + 48;
    }
    else if (*str < 'Z' && *str > 'A') {
        *str = arr[(int)*str - 65] + 48;
    }
    return letterToNumber(str + 1, arr);
}

int main() {
    char str[11] = "Cauchi";
    int arr[26] = {3, 5, 0, 3, 3, 7, 6, 5, 1, 1, 7, 2, 3, 9, 0, 5, 2, 5, 2, 7, 5, 7, 4, 9, 7, 7};
    letterToNumber(str, arr);
    cout << str << endl;
    return 0;
}
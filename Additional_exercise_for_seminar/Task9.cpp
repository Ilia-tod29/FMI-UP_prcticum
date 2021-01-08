#include <iostream>

using std::cin;
using std::cout;
using std::endl;

char letterSwap (char* str, bool* arr) {
    if (*str == '\0') {
        return *str;
    }
    if ((*str <= 'z' && *str >= 'a') && *arr) {
        *str -= 32;
    }
    return letterSwap(str + 1, arr + 1);
}

int main() {
    char str[13] = "Lorem Ip%sum";
    bool arr[12] = {false, true, true, false, true, true, true, false, false, false, false, false};
    letterSwap(str, arr);
    cout << str << endl;
    return 0;
}
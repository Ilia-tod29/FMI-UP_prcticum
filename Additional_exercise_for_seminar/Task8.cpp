#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool validation (char* str) {
    while (*str) {
        if (*(str + 1) == '\0') {
            if (*str == '.' || *str == '!' || *str == '?' ){
                return true;
            }
        }
        *str++;
    }
    cout << "Invalid data!" << endl;
    return false;
}
double averageStr (char* str) {
    int letterCount = 0, wordsCount = 0;
    while (*str) {
        if (*str <= 'z' && *str >= 'a' || *str < 'Z' && *str > 'A') {
            letterCount++;
        }
        else if (*str == ' ') {
            wordsCount++;
            if (*(str + 1) == *str) {
                wordsCount--;
            }
        }
        *str++;
    }
    if (wordsCount == 0) {
        wordsCount = 2;
    }
    wordsCount++;
    return letterCount / wordsCount;
}

int main() {
    char str[16] = "Lorem  Ipsum.";
    bool isValid = validation(str);
    if (isValid) {
        cout << "The average word length of your string is: " << averageStr(str) << endl;
    }
    return 0;
}
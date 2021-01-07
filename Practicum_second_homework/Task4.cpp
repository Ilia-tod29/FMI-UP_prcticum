#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//Recursive function for getting the cont of the digits in a string
int digitsCount (const char* str, int count) {
    //End of recursion
    if (*str == '\0') {
        return count;
    }
    //Check if the current symbol is a digit
    if (*str >= '0' && *str <= '9') {
        count++;
    }
    //Calling the same function
    return digitsCount(str + 1, count);
}
int main() {
    //Setting params with which you want to call the function
    char str[100] = "5ducksflew10k#~@321234567890*-+ilome3ter5sin8ho1urs23";
    int counter = 0;
    counter = 0;
    //Calling the function
    cout << "The count of digits in your string is: " << digitsCount(str, counter);
    return 0;
}
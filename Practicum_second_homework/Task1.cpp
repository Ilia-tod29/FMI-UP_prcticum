#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//Initializing the maximum length of the arrays
const int MAX_SIZE = 100;

//Check if every letter of first given string is contained in the other one, using the help of a static variable
static int counter = 0;
bool doesContains(const char* str1, const char* str2) {
    //The check itself
    for (int i = 0; *(str2 + i) != '\0' ; ++i) {
        if (*str1 == *(str2 + i) || *str1 == '\0') {
            counter++;
            break;
        }
    }
    //End of recursion
    if (counter == 0) {
        return false;
    }
    if (*str1 == '\0') {
        return true;
    }
    //Setting the counter back to 0
    counter = 0;
    //Calling the same function
    return doesContains((str1 + 1), str2);
}
int main() {
    //Setting params with which you want to call the function
    char str1[MAX_SIZE] = "good book";
    char str2[MAX_SIZE] = "gb kod";
    //Calling the function
    bool answer = doesContains(str1, str2);
    if(answer) {
        cout << "YES, the second string contains all the letters from the first one." << endl;
    }
    else {
        cout << "NO, the second string do not contains all the letters from the first one." << endl;
    }
    return 0;
}

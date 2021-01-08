#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void removeSpaces(char* s)
{
    char* cpy = s;
    char* temp = s;

    while (*cpy)
    {
        if (*cpy != ' ')
            *temp++ = *cpy;
        cpy++;
    }
    *temp = 0;
}
int lettersCount (const char* str) {
    int counter = 0;
    while (*str != '\0') {
        counter++;
        *str++;
    }
    return counter;
}
bool isAnagram (char* str1, char* str2) {
    if (lettersCount(str1) == lettersCount(str2)) {
        int helpNum = 0;
        while (str1[helpNum] != '\0' && str2[helpNum] != '\0') {
            char currentLetter = str1[helpNum];
            int counter1 = 0, counter2 = 0, i = 0;
            while (str1[i] != '\0') {
                if (str1[i] == currentLetter || str1[i] + 32 == currentLetter || str1[i] - 32 == currentLetter) {
                    counter1++;
                }
                i++;
            }
            i = 0;
            while (str2[i] != '\0') {
                if (str2[i] == currentLetter || str2[i] + 32 == currentLetter || str2[i] - 32 == currentLetter) {
                    counter2++;
                }
                i++;
            }
            if (counter1 != counter2) {
                return false;
            }
            helpNum++;
        }
        return true;
    }
    else {
        return false;
    }
}
int main() {
    char str[19] = "A B B A";//"Hi my name is Ilia";//"Astronomer";
    char str1[19] = "baba"; //"hI name My siAilti";//"Moon starer";
    removeSpaces(str);
    removeSpaces(str1);
    cout << std::boolalpha << isAnagram(str, str1) << endl;
    return 0;
}

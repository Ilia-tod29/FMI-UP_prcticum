#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//Initializing the maximum length of the arrays
const int MAX_SIZE = 100;
//Function for printing the code deciphered
void printCode (char* code) {
    cout << code << endl;
}
//Function for decryption of a Caesar code
char* caesarCipher (char* code, int decryption) {
    for (int i = 0; *(code + i) != '\0'; ++i) {
        if ((*(code + i) - decryption) < 65) {
            *(code + i) -= decryption;
            *(code + i) += 26;
        }
        else {
            *(code + i) -= decryption;
        }
    }
    return code;
}
//Function for validation of the data which thr user has entered
void validation (char* code, int decryption) {
    bool isValid = true;
    for (int i = 0; *(code + i) != '\0'; ++i) {
        if(*(code + i) < 65 || *(code + i) > 90) {
            isValid = false;
        }
    }
    if (isValid) {
        caesarCipher(code, decryption);
    }
    else {
        cout << "Invalid data!" << endl;
    }
}

int main() {
    //Setting params with which you want to call the function
    char sentence[MAX_SIZE] = "YWFNHMTJRSTLTLTYNS";
    int n = 4;
    //Calling the functions
    validation(sentence, n);
    printCode(sentence);
    return 0;
}
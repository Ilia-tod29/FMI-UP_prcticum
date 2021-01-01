#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int MAX_SIZE = 100;

//TASK1
void reverse(int *arr, int n) {
    for (int i = n; i > 0; --i) {
        cout << *(arr + i  - 1) << ",";
    }
    cout << endl;
}
//TASK2
void func(const char* arr, int n) {
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (*(arr + i) >= 48 && *(arr + i) <= 57)
            counter++;
    }
    cout << counter << endl;
}
//TASK3
bool isVriable(char *arr) {
    int i = 0;
    while(*(arr + i) != '\0') {
        if(!(*(arr + i) >= 48 && *(arr + i) <= 57) && !(*(arr + i) >= 65 && *(arr + i) <= 90) && !(*(arr + i) >= 97 && *(arr + i) <= 122)) {
            return false;
        }
        i++;
    }
    return true;
}
//TASK4
void operations(int *arr, int n) {
    int i = 0;
    int op;
    if (n == 1) {
        while(*(arr + 1) != 0) {
            for (int i = n; i > 0; --i) {
                cout << *(arr + i  - 1) << ",";
            }
            cout << endl;
        }
    }
    else if (n == 2) {

    }
    else if (n == 3) {

    }
    else if (n == 4) {

    }
    else if (n == 5) {

    }
    else{
        cout << "Invalid Data!" << endl;
    }
}
//TASK5
void squareMatrix(int* matrix[], int size){
    int rowSum = 0, columnSum = 0, mainDiagonalSum = 0, underMainDiagonalSum = 0, overMainDiagonalSum = 0,
        secondDiagonalSum = 0, underSecondDiagonalSum = 0, overSecondDiagonalSum = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            rowSum += matrix[i][j];
            columnSum += matrix[i][j];

            if (i == j) {
                mainDiagonalSum += matrix[i][j];
            }
            if (j < i) {
                underMainDiagonalSum += matrix[i][j];
            }
            if (j > i) {
                overMainDiagonalSum += matrix[i][j];
            }
            if ((i + j) == (size - 1)) {
                secondDiagonalSum += matrix[i][j];
            }
            if ((i + j) > (size - 1)) {
                underSecondDiagonalSum += matrix[i][j];
            }
            if ((i + j) < (size - 1)) {
                overSecondDiagonalSum += matrix[i][j];
            }
        }
    }
    cout << "SUM: " << endl;
    cout << "Row: " << rowSum << endl;
    cout << "Column: " << columnSum << endl;
    cout << "Main diagonal: " << mainDiagonalSum << endl;
    cout << "Under main diagonal: " << underMainDiagonalSum << endl;
    cout << "Over main diagonal: " << overMainDiagonalSum << endl;
    cout << "Second diagonal: " << columnSum << endl;
    cout << "Under second diagonal: " << underSecondDiagonalSum << endl;
    cout << "Over second diagonal: " << overSecondDiagonalSum << endl;
}





int main () {
    char arr[MAX_SIZE] = {'1', 'h', 'i', '9', 'j', '2'};
    func(arr, 6);

    int mass[MAX_SIZE] = { 1, 2, 3, 4, 5};
    reverse(mass, 5);

    char var1[MAX_SIZE] = "#hi23";
    cout << isVriable(var1) << endl;

    return 0;
}
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int const MAX_SIZE = 100;

//TASK0
void swap (int num1, int num2) {
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;

    cout << num1 << " " << num2 << endl;
}

//TASK1
void Pow (double num, int power) {
    double helpPow = num;
    for (size_t i = 1; i < power; ++i) {
        num *= helpPow;
    }
    cout << num << endl;
}

double Min (double n1, double n2) {
    if (n1 >= n2) {
        return n2;
    }
    return n1;
}

double Max (double n1, double n2) {
    if (n1 >= n2) {
        return n1;
    }
    return n2;
}

void minOf3 (double n1, double n2, double n3) {
    if (Min(n1, n2) >= Min(n2, n3)) {
        cout << Min(n2, n3) << endl;
    }
    else {
        cout << Min(n1, n2) << endl;
    }
}

void maxOf3 (double n1, double n2, double n3) {
    if (Max(n1, n2) <= Max(n2, n3)) {
        cout << Max(n2, n3) << endl;
    }
    else {
        cout << Max(n1, n2) << endl;
    }
}

bool isAlpha (char sym) {
    if (sym >= 'a' && sym <= 'z') {
        return true;
    }
    return false;
}

bool isDigit (char sym) {
    if (sym >= '0' && sym <= '9') {
        return true;
    }
    return false;
}

//TASK2
void printMatrix (const int matrix[][MAX_SIZE], int rows, int columns) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            cout << matrix[i][j] << " ";

        }
        cout << endl;
    }
}
void generateMatrix (int rows, int columns) {
    int matrix[MAX_SIZE][MAX_SIZE] = {0};

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            if (i == j) {
                matrix[i][j] = i;
            }
            if (j > i) {
                matrix[i][j] = j - i;
            }
            if (j < i) {
                matrix[i][j] = i * j;
            }
        }
    }
    printMatrix(matrix, rows, columns);
}

//TASK3
void square (double x) {
    cout << x * x << endl;
}

//TASK4
void printArr (const int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printArrD (const double arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void multiply (int array[], int num) {
    int i = 0;
    while (array[i] != 0) {
        array[i] *= num;
        i++;
    }
    printArr(array, i);
}

void multiplyD (double array[], double num) {
    int i = 0;
    while (array[i] != 0) {
        array[i] *= num;
        i++;
    }
    printArrD(array, i);
}
//TASK 5
bool isArrLowering (const int arr[]) {
    bool flag = true;
    for (size_t i = 1; i < 10; ++i) {
        if (arr[i] > arr[i-1]) {
            flag = false;
            break;
        }
    }
    return flag;
}
//TASK6
void howManyWords (const char arr[]) {
    int i = 0, counter = 0;
    while (arr[i] != '\0') {
        if (arr[i] == ' ') {
            counter++;
        }
        i++;
    }
    cout << "Your string has " << (counter + 1) << " words." << endl;
}
//TASK7
void howManyDigits (const char arr[]) {
    int i = 0, counter = 0;
    while (arr[i] != '\0') {
        if (arr[i] >= '0' && arr[i] <= '9') {
            counter++;
        }
        i++;
    }
    cout << "Your string has " << counter << " digits." << endl;
}
//TASK8
bool isIdentifier (const char arr[]) {
    int i = 0;
    if (arr[0] >= '0' && arr[0] <= '9') {
        return false;
    }

    while (arr[i] != '\0') {
        if ((arr[i] > 'z' || arr[i] < 'a') && (arr[i] > 'Z' || arr[i] < 'A') && arr[i] != '_') {
            return false;
        }
        i++;
    }
    return true;
}

//BONUS0
//1) determinant
void determinant (const int matrix[][MAX_SIZE]) {
    int determinant = (matrix[1][1] * matrix[2][2] * matrix[3][3]) + (matrix[1][2] * matrix[2][3] * matrix[3][1]) + (matrix[1][3] * matrix[2][1] * matrix[3][2])
            - (matrix[3][1] * matrix[2][2] * matrix[1][3]) - (matrix[3][2] * matrix[2][3] * matrix[1][1]) - (matrix[3][3] * matrix[2][1] * matrix[1][2]);
    cout << "The determinant is equal to: " << determinant << endl;
}

//2) transposition
void transponation (int matrix[][MAX_SIZE], int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
}

//3) addition
void addition (int matrix[][MAX_SIZE], int matrix2[][MAX_SIZE], int rows, int columns) {
    int addedMatrix[MAX_SIZE][MAX_SIZE] = {0};
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            addedMatrix[i][j] += (matrix[i][j] + matrix2[i][j]);
        }
    }
    printMatrix(addedMatrix, rows, columns);
}

//4) subtraction
void subtraction (int matrix[][MAX_SIZE], int matrix2[][MAX_SIZE], int rows, int columns) {
    int subtractedMatrix[MAX_SIZE][MAX_SIZE] = {0};
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            subtractedMatrix[i][j] = matrix[i][j] - matrix2[i][j];
        }
    }
    printMatrix(subtractedMatrix, rows, columns);
}

//5) multiplication
void multiplication (int matrix[][MAX_SIZE], int matrix2[][MAX_SIZE], int rows, int columns) {
    int multiliedMatrix[MAX_SIZE][MAX_SIZE] = {0};
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            for (int k = 0; k < columns; ++k) {
                multiliedMatrix[i][j] += matrix[i][k] * matrix2[k][j];
            }
        }
    }
    printMatrix(multiliedMatrix, rows, columns);
}
//BONUS1
//bubbleSort
void swap (double* n1, double* n2) {
    double temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}
void bubbleSort (double arr[], int n) {
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    printArrD(arr, n);
}

void selectionSort (double arr[], int n) {
    for (size_t i = 0; i < n; i++) {
        int minIindex = i;
        for (size_t j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                minIindex = j;
            }
        }
        swap(&arr[i], &arr[minIindex]);
    }
    printArrD(arr, n);
}

void insertSort(double arr[], int n) {
    double key;
    int index;
    for (int i = 0; i < n; ++i) {
        key = arr[i];
        index = i;
        while (index > 0 && arr[index - 1] > key) {
            arr[index] = arr[index - 1];
            index--;
        }
        arr[index] = key;
    }
    printArrD(arr, n);
}




int main() {

    cout << "---------TASK0---------" << endl;
    swap(5, 8);

    cout << "---------TASK1---------" << endl;
    cout << "POW: ";
    Pow(9.1, 2);

    cout << "MIN: ";
    double pi = 3.14;
    double e = 2.71;
    cout << Min(e, pi) << endl;

    cout << "MAX: ";
    cout << Max(e, pi) << endl;

    cout << "Min of 3: ";
    double g = 15.2;
    minOf3(e, pi, g);

    cout << "Max of 3: ";
    maxOf3(e, pi, g);

    cout << "Is alpha: ";
    cout << std::boolalpha << isAlpha('a') << endl;
    cout << "Is alpha: ";
    cout << std::boolalpha << isAlpha('%') << endl;

    cout << "Is digit : ";
    cout << std::boolalpha << isDigit('5') << endl;
    cout << "Is digit : ";
    cout << std::boolalpha << isDigit('a') << endl;

    cout << "---------TASK2---------" << endl;
    generateMatrix(5, 6);

    cout << "---------TASK3---------" << endl;
    square(2.5);

    cout << "---------TASK4---------" << endl;
    cout << "For int: " << endl;
    int arr[MAX_SIZE] = {1, 5, 6, 15, 18, 24, 30, 50};
    multiply(arr, 2);
    cout << "For double: " << endl;
    double arrD[MAX_SIZE] = {10.1, 55.3, 6.5, 15.3, 13.9, 21.7, 30,  50.6};
    multiplyD(arrD, 2);

    cout << "---------TASK5---------" << endl;
    int loweringArr[MAX_SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    cout << "Is array lowering? " << std::boolalpha << isArrLowering(arr) << endl;
    cout << "Is array lowering? " << std::boolalpha << isArrLowering(loweringArr) << endl;

    cout << "---------TASK6---------" << endl;
    cout << "Enter a string: ";
    char text[MAX_SIZE] = {0};
    cin.getline(text, MAX_SIZE);
    howManyWords(text);

    cout << "---------TASK7---------" << endl;
    cout << "Enter a string: ";
    char textWithDigits[MAX_SIZE] = {0};
    cin.getline(textWithDigits, MAX_SIZE);
    howManyDigits(textWithDigits);

    cout << "---------TASK8---------" << endl;
    cout << "Enter a variable name: ";
    char isVar[MAX_SIZE] = {0};
    cin.getline(isVar, MAX_SIZE);
    cout << "Your variable name is OK: " << std::boolalpha << isIdentifier(isVar) << endl;

    cout << "---------BONUS0---------" << endl;
    int matrix1[MAX_SIZE][MAX_SIZE] = {{1, 2, 3},
                                      {4, 5, 6},
                                      {7, 8, 9}};
    int matrix2[MAX_SIZE][MAX_SIZE] = {{11, 12, 13},
                                       {14, 15, 16},
                                       {17, 18, 19}};
    cout << "Determinat of matrix 1 is equal to: ";
    determinant(matrix1);
    cout << endl;
    cout << "Determinat of matrix 1 is equal to: ";
    determinant(matrix2);
    cout << endl;

    cout << "Matrix1 transponationed: " << endl;
    transponation(matrix1, 3, 3);
    cout << endl;
    cout << "Matrix2 transponationed: " << endl;
    transponation(matrix2, 3, 3);
    cout << endl;

    cout << "Matri1 + Matrix2: " << endl;
    addition(matrix1, matrix2, 3, 3);
    cout << endl;

    cout << "Matri1 - Matrix2: " << endl;
    subtraction(matrix1, matrix2, 3, 3);
    cout << endl;

    cout << "Matri1 * Matrix2: " << endl;
    multiplication(matrix1, matrix2, 3, 3);
    cout << endl;

    cout << "---------BONUS0---------" << endl;
    cout << "Bubble sort" << endl;
    bubbleSort(arrD, 8);
    cout << "Selection sort" << endl;
    selectionSort(arrD, 8);
    cout << "Inserting sort" << endl;
    insertSort(arrD, 8);


    return 0;
}

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
const int MAX_SIZE = 100;
//TASK0
int* halfArr(int* arr,int n) {
    int *newArrptr = new int[n/2];
    for (int i = 0; i < n/2; ++i) {
        newArrptr[i] = arr[i];
    }
    return newArrptr;
}

//TASK2
int* resize (int source[], int oldSize, int newSize) {
    int* newArrPtr = new int[newSize];
    for (int i = 0; i < oldSize; ++i) {
        newArrPtr[i] = source[i];
    }
    return newArrPtr;
}

//TASK3
int size (const int source[]) {
    int sz = 0;
    while(source[sz] != 0) {
        sz++;
    }
    return sz;
}

int* newArr(const int source[]) {
    int sz = size(source);
    int *destination = new int[sz];
    for (int i = 0; i < sz; ++i) {
        destination[i] = source[i];
    }
    return destination;
}

//TASK4
void reverseArr (char* arr, int size) {
    for (int i = 0; i < size / 2; ++i) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}
char* toChArr (int num) {
    int i = 0;
    char* charArr = new char[i];
    while(num != 0) {
        charArr[i] = (num % 10) + 48;
        ++i;
        num /= 10;
    }
    reverseArr(charArr, i);
    charArr[i] = '\0';
    return charArr;
}

int main() {
    //TASK0
    int* arr;
    arr = halfArr(arr, 10);

    delete[] arr;


    //TASK1
    //В една школа има определен брой учители. Всеки един от тях иска да нанесе определен брой оценки. Дайте на учителите места, където да си нанесат оценките.
    size_t teachersSize;
    cin >> teachersSize;
    //На всеки ред ще имаме масив, където учителите да поставят оценки

    double** marks = new double*[teachersSize];
    //double marks = new double[teachersSize][];

    for(int i = 0; i < teachersSize; i++) {
        size_t HowManyGrades;
        cin >> HowManyGrades;

        // правим местенце за оценките
        marks[i] = new double[HowManyGrades];

        for (int j = 0; j < HowManyGrades; j++) {
            cin >> marks[i][j];
        }
    }
    for (int i = 0; i < teachersSize; ++i) {
        delete[] marks[i];
    }
    //TASK2
    int startArr[3] = {1, 2, 3};
    int* newArr = resize(arr, 3, 4);
    delete newArr;

    //TASK4
    int number = 123456;
    char* charArr;
    charArr = toChArr(number);
    for (int i = 0; i < 6; ++i) {
        cout << charArr[i] << " ";
    }
    cout << endl;
    delete[] charArr;

    return 0;
}

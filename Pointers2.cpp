#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int MAX_SIZE = 100;
//TASK0
void swap (int* num1, int* num2) {
    int helpNum = *num1;
    *num1 = *num2;
    *num2 = helpNum;
}
//TASK1
void arrPrint (const int *arr,int size) {
    for (int i = 0; i < size; ++i) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}
void reverse (int *arr, int size) {
    for (int i = 0; i < size / 2; ++i) {
        int helpNum = *(arr + i - 1);
        *(arr + i - 1) = *(arr + size - i);
        *(arr + size - i) = helpNum;
    }
    arrPrint(arr, size);
}
//TASK2
int* findNum (int* arr, int size, int num) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == num) {
            return &arr[i];
        }
    }
    return nullptr;
}
//TASK3
void sortedComb (const int arr[], const int arr2[], int size, int size2) {
    int emptyArr[MAX_SIZE * 2] = {0};
    for (int i = 0; i < size; ++i) {
        emptyArr[i] = arr[i];
    }
    for (int i = size; i < (size + size2); ++i) {
        emptyArr[i] = arr2[i - size];
    }
    for (int i = 0; i < (size + size2 - 1); ++i) {
        for (int j = 0; j < (size + size2 - i - 1); ++j) {
            if (emptyArr[j] > emptyArr[j + 1]) {
                swap(&emptyArr[j], &emptyArr[j + 1]);
            }
        }
    }
    arrPrint(emptyArr, size + size2);
}
//TASK4
void minSumPtr (int arr[], int size, int arr1[], int size1, int *ptr) {
    int sum = 0, sum1 = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    for (int i = 0; i < size1; ++i) {
        sum1 = arr1[i];
    }
    if(sum > sum1) {
        ptr = arr;
    }
    else {
        ptr = arr1;
    }
    cout << ptr << endl;
}


int main() {
    int a = 10;
    int b = 15;
    swap(&a, &b);
    cout << "a = " << a << " b = " << b << endl;

    int array[MAX_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    reverse(array, 10);

    int array1[MAX_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << findNum(array1, 10, 6) << endl;

    int sortArr1[MAX_SIZE] = {1, 8, 9, 12, 15, 20, 50};
    int sortArr2[MAX_SIZE] = {2, 5, 10, 30, 25, 60};
    sortedComb(sortArr1, sortArr2, 7, 6);

    int arrFor4[MAX_SIZE] = {1, 2, 6, 8, 9, 10, 12, 15};
    int arrFor41[MAX_SIZE] = {2, 5, 10, 30, 25, 60};
    int *ptr = nullptr;
    minSumPtr(arrFor4, 8, arrFor41, 6, ptr);
    return 0;
}

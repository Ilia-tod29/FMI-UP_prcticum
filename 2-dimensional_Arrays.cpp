#include <iostream>

using namespace std;
const int MAX_SIZE = 100;
int main() {

    int twoDimArr[MAX_SIZE][MAX_SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, twoDimArr1[MAX_SIZE][MAX_SIZE];
    int n = 3, sum = 0, sumDiagonals = 0, minEl = INT32_MAX, maxEl = INT32_MIN, sumRow[MAX_SIZE] = {0}, sumColumn[MAX_SIZE] = {0}, sumMaiDiagonal = 0, sumUnderMainDiagonal = 0,
    sumOverMainDiagonal = 0, sumSecondDiagonal = 0, sumUnderSecondDiagonal = 0, sumOverSecondDiagonal = 0, x, indexOfxRows, indexOdxColumns;
    bool isInMatrix = false;
    cin >> x;

    for (size_t i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            //Task1
            sum += twoDimArr[i][j];
            //Task2
            if ((j == i) || ((i + j) == (n - 1))) {
                sumDiagonals += twoDimArr[i][j];
            }
            //Task3
            twoDimArr1[i][j] = twoDimArr[i][j] + 10;
            //Task4
            if (minEl > twoDimArr[i][j]) {
                minEl = twoDimArr[i][j];
            }
            if (maxEl < twoDimArr[i][j]) {
                maxEl = twoDimArr[i][j];
            }
            //Task5
            sumRow[i] += twoDimArr[i][j];
            sumColumn[j] += twoDimArr[i][j];

            if (i == j) {
                sumMaiDiagonal += twoDimArr[i][j];
            }
            if (j < i) {
                sumUnderMainDiagonal += twoDimArr[i][j];
            }
            if (j > i) {
                sumOverMainDiagonal += twoDimArr[i][j];
            }
            if ((i + j) == (n - 1)) {
                sumSecondDiagonal += twoDimArr[i][j];
            }
            if ((i + j) > (n - 1)) {
                sumUnderSecondDiagonal += twoDimArr[i][j];
            }
            cout << sumUnderSecondDiagonal << endl;
            if ((i + j) < (n - 1)) {
                sumOverSecondDiagonal += twoDimArr[i][j];
            }
            //Task6
            if(twoDimArr[i][j] == x) {
                isInMatrix = true;
                x = twoDimArr[i][j] * 10;
                indexOfxRows = i;
                indexOdxColumns = j;
            }
        }
    }
    cout << "Task1------------------------" << endl;
    cout << sum << endl;
    cout << "Task2------------------------" << endl;
    cout << sumDiagonals << endl;
    cout << "Task3------------------------" << endl;
    for (size_t i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << twoDimArr1[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Task4------------------------" << endl;
    cout << minEl << endl;
    cout << maxEl << endl;
    cout << "Task5------------------------" << endl;
    for (size_t i = 0; i < n; ++i) {
        cout << sumRow[i] << endl;
    }
    cout << "------------------------" << endl;
    for (size_t i = 0; i < n; ++i) {
        cout << sumColumn[i] << endl;
    }
    cout << "------------------------" << endl;
    cout << sumMaiDiagonal << endl;
    cout << "------------------------" << endl;
    cout << sumUnderMainDiagonal << endl;
    cout << "------------------------" << endl;
    cout << sumOverMainDiagonal << endl;
    cout << "------------------------" << endl;
    cout << sumSecondDiagonal << endl;
    cout << "------------------------" << endl;
    cout << sumUnderSecondDiagonal << endl;
    cout << "------------------------" << endl;
    cout << sumOverSecondDiagonal << endl;
    cout << "Task6------------------------" << endl;
    if (isInMatrix) {
        cout << "Yes, on position: " << indexOfxRows << indexOdxColumns << endl;
        cout << x;
    }
    else {
        cout << "Your number is not in the matrix!";
    }


    //Task7
    int arr[MAX_SIZE] = {1, 2, 3, 4, 8, 3, 5, 121, 15, 55};
    int n = 10;

    for (size_t i = 0; i < n; ++i) {
        int min = arr[i], minIndex = i;
        for (size_t j = i + 1; j < n; ++j) {
            if(min > arr[j]) {
                min = arr[j];
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = min;
        arr[minIndex] = temp;
    }

    for (size_t i = 0; i < n; ++i) {
        cout << arr[i] << endl;
    }













    return 0;
}

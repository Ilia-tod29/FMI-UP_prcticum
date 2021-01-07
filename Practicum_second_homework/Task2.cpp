#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//Function for printing the matrix
void printMatrix (int* matrix[],  int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
//Function for generating a matrix by given number and following the conditions
void generateMatrix (int n) {
    //Initializing the matrix dynamically
    int** matrix = new int*[n];
    //Filling the matrix
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            if ((i + j) == (n - 1)) {
                matrix[i][j] = 1;
            }
            else if ((i + j) < (n - 1)) {
                matrix[i][j] = 0;
            }
            else {
                matrix[i][j] = 2;
            }
        }
    }
    //Calling the function for printing the matrix
    printMatrix(matrix, n);
    //Deleting the matrix after displaying it
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
}
int main() {
    //Setting params with which you want to call the function
    int num;
    cout << "Please enter a number to set the size of your matrix: ";
    cin >> num;
    cout << endl;
    //Calling the function
    generateMatrix(num);
    return 0;
}
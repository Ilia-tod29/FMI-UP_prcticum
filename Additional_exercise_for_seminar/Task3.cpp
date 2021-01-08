#include <iostream>

using std::cin;
using std::cout;
using std::endl;
const int MAX_SIZE = 100;
bool isSymmetrical (const int arr[][MAX_SIZE], const int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] != arr[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE] = {{4, -5, 2}, {-5, 0, 1}, {2, 1, 8}};
    cout << std::boolalpha << isSymmetrical(matrix, 3) << endl;
    return 0;
}

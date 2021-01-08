#include <iostream>

using std::cin;
using std::cout;
using std::endl;
const int MAX_SIZE = 100;

void isPowerOfTwo (int n) {
    while (n != 0) {
        if (n % 2 != 0) {
            cout << "NO" << endl;
            return;
        }
        n /= 2;
    }
    cout << "YES" << endl;
}
int sum (const int matrix[MAX_SIZE][MAX_SIZE], const int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                sum += matrix[i][j];
            }
            if ((i + j) == (n - 1)) {
                sum += matrix[i][j];
                if (n % 2 == 1) {
                    if (i == n / 2){
                        sum -= matrix[i][j];
                    }
                }
            }
        }
    }
    isPowerOfTwo(sum);
    return sum;
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << sum(matrix, 3) << endl;
    return 0;
}
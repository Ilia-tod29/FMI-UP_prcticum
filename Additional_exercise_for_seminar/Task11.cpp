//
// Created by Ilia on 1/11/2021.
//
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int binaryToDecimal(int n)
{
    int num = n;
    int decimal = 0;
    int base = 1;

    int temp = num;
    while (temp) {
        int lastDigit = temp % 10;
        temp = temp / 10;

        decimal += lastDigit * base;

        base *= 2;
    }

    return decimal;
}

int minBinary (int num) {
    if (num == 1) {
        return 1;
    }
    return 1 * 10 * minBinary(num - 1) + 1;
}

int main() {
    int n = 4;
    n = minBinary(n);
    cout << binaryToDecimal(n) << endl;

    return 0;
}
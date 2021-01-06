#include <iostream>

using std::cin;
using std::cout;
using std::endl;


//Задача 0
//Напишете рекурсивна функция с прототип int sumOfDigits(int) ,
//която връща като резултат сборът от цифрите на цяло положително число с променлива дължина.
//Задача 1
//Напишете рекурсивна функция с прототип int recStrlen(const char*) , която връща като резултат дължината на подадения низ.
//Задача 2
//Напишете рекурсивна функция с прототип int reverse(int), която обръща цяло число
//(от дадено число получава ново число, в което цифрите са в обратен ред).
//Задача 3
//Напишете рекурсивна функция int factorial(int) , която пресмята факториел от дадено цяло число.
//Задача 4
//Да се напише рекурсивна функция bool areEqual(char* str1, char* str2), която проверява дали двата стринга са равни.
//Задача 5
//Да се реализира рекурсивна функция, която намира n-тия член от редицата на Фибоначи.
//Задача 6
//Напишете рекурсивна функция, която приема масив и връща минималния му елемент.
//Задача 7
//Напишете функция, която приема число в десетична бройна система и връща числото в двоична бройна система
//Задача 8
//Напишете функция с прототип void evaluate(const char*),
//която намира и изпечатва броят на малки и големи букви и броят на цифрите в даденият низ
//Задача 9
//Напишете функция с прототип bool swapcase(char*), която променя всяка голяма буква на малка и всяка малка на голяма в подадения низ

//TASK0
int sumOfDigits (int n) {
    if (n == 0) {
        return 0;
    }
    return (n % 10) + sumOfDigits(n / 10);
}

//TASK1
int recStrlen (const char* arr) {
    if (arr[0] == '\0') {
        return 0;
    }
    return 1 + recStrlen(arr + 1);
}

//TASK2
int reverse (int num, int reversed) {
    if (num == 0) {
        return reversed;
    }
    return reverse(num / 10, (num % 10) + (reversed * 10));
}

//TASK3
int factoriel (int num) {
    if (num == 1) {
        return 1;
    }
    return (num % 10) * factoriel(num - 1);
}

//TASK4
bool areEqual (const char* str1, const char* str2) {
    if (*str1 != *str2) {
        return false;
    }
    else if ((*str1 == '\0' && *str2 != '\0') || (*str2 == '\0' && *str1 != '\0')) {
        return false;
    }
    else if (*str1 == '\0' && *str2 == '\0') {
        return true;
    }
    return areEqual((str1 + 1), (str2 + 1));
}

//TASK5
int fibonacci (int num) {
    if (num == 1) {
        return 1;
    }
    else if(num == 0) {
        return 0;
    }
    return fibonacci(num - 1) + fibonacci(num - 2);
}

//TASK6
static int minEL = INT16_MAX;
int minElement (int* arr, int length) {
    if (*arr < minEL) {
        minEL = *arr;
    }
    if (length == 1) {
        return minEL;
    }
    return minElement(arr + 1, length - 1);
}

//TASK7
int toBinary (int num) {
    if (num == 0) {
        return 0;
    }
    if (num == 1) {
        return 1;
    }
    return (num % 2) + toBinary(num / 2) * 10;
}

//TASK8


int main() {
    //TASK0
    cout << sumOfDigits(154) << endl;

    //TASK1
    //char *sentence = new char[15];
    //sentence = "Happy new year";
    char sentence[15] = "Happy new year";
    cout << recStrlen(sentence) << endl;
    //delete[] sentence;

    //TASK2
    cout << reverse(1123, 0) << endl;

    //TASK3
    cout << factoriel(5) << endl;

    //TASK4
    cout << std::boolalpha << areEqual("Hello", "Hello") << endl;

    //TASK5
    cout << fibonacci(2) << endl;

    //TASK6
    int arrMin[5] = {10, 5, 4, 15, 16};
    cout << minElement(arrMin, 5) << endl;

    //TASK7
    cout << toBinary(5) << endl;


    return 0;
}

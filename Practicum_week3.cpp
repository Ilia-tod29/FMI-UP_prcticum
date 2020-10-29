#include <iostream>
#include <cmath>
using namespace std;

int main() {
    //--------------------------------------------------------------------------------------------
    //WEEK 3
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    //Task 0
    //--------------------------------------------------------------------------------------------
    int n, factoriel = 1;
    cin >> n;
    for (int i = 1; i <= n ; i++) {
        factoriel = factoriel * i;
    }
    cout << factoriel << endl;

    //--------------------------------------------------------------------------------------------
    //Task 1
    //--------------------------------------------------------------------------------------------

    int n1;
    cin >>n1;
    for(int i = 1; i <= n1; i++)
    {
        cout << i*i + 3*i << endl;
    }

    //--------------------------------------------------------------------------------------------
    //Task 2
    //--------------------------------------------------------------------------------------------

    int n2, num, maxNegative = 0;
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        cin >> num;
        if(num < 0){
            if(maxNegative == 0) {
                maxNegative = num;
            }
            else if(num > maxNegative){
                maxNegative = num;
            }
        }
    }
    if(maxNegative == 0){
        cout << "There are no negative numbers!" <<endl;
    }
    else{
        cout << "The max negative number is: " << maxNegative << endl;
    }

    //--------------------------------------------------------------------------------------------
    //Task 3
    //--------------------------------------------------------------------------------------------
    int n3, f1 = 1, f0 = 0, help;
    cin >> n3;
    cout << f0 << ", " << f1;
    for (int i = 2; i < n3; i++) {
        help = f1 + f0;
        cout << ", " << help;
        f0 = f1;
        f1 = help;
    }

    //--------------------------------------------------------------------------------------------
    //Task 4
    //--------------------------------------------------------------------------------------------
    int n4, sum = 0;
    cin >> n4;
    while (n4 != 0){
        sum += n4;
        cin >> n4;
    }
    cout << sum << endl;

    //--------------------------------------------------------------------------------------------
    //Task 5
    //--------------------------------------------------------------------------------------------
    int n5, sum1;
    cin >> n5;
    while(n5 != 0){
        sum1 += n5 % 10;
        n5 /= 10;
    }
    cout << sum1;


    //--------------------------------------------------------------------------------------------
    //Task 6
    //--------------------------------------------------------------------------------------------
    int num6, poww, help6;
    cin >> num6 >> poww;
    help6 = num6;
    for (int i = 1; i < poww; i++) {
        num6 *= help6;
    }
    cout << num6 << endl;



    //--------------------------------------------------------------------------------------------
    //Task 7
    //--------------------------------------------------------------------------------------------
    int num7;
    cin >> num7;
    bool isSimple = 1;
    for (int i = 2; i < (num7 / 2); i++) {
        if(num7 % i == 0) {
            isSimple = 0;
            cout << "NO" << endl;
            break;
        }
    }
    if(isSimple){
        cout << "YES" << endl;
    }


    //--------------------------------------------------------------------------------------------
    //Task 8
    //--------------------------------------------------------------------------------------------
    for (int i = 65; i <= 90; i++) {
        if(char(i) != 'A' && char(i) != 'E' && char(i) != 'I' && char(i) != 'O' && char(i) != 'U' && char(i) != 'Y'){
            cout << char(i) << " ";
        }
    }

    //--------------------------------------------------------------------------------------------
    //Task 9
    //--------------------------------------------------------------------------------------------
    int num9;
    cin >> num9;
    for (int i = 0; i < num9; i++) {
        for (int j = 0; j < num9; j++) {
            if (j < i) {
                cout << "-";
            }
            else if (j == i) {
                cout << "0";
            }
            else {
                cout << "+";
            }
        }
        cout << endl;
    }


    //--------------------------------------------------------------------------------------------
    //Additional tasks
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    //Task 0
    //--------------------------------------------------------------------------------------------
    int num0;
    cout << "Enter a number and find out if it has 1 in it: ";
    cin >> num0;
    while(num0 != 0){
        if (num0 % 10 == 1) {
            cout << "YES" << endl;
            break;
        }
        num0 /= 10;
    }
    if (num0 == 0) {
     cout << "NO" << endl;
    }

    //--------------------------------------------------------------------------------------------
    //Task 1
    //--------------------------------------------------------------------------------------------
    int num1, num2;
    int hour1, minuets1, hour2, minuets2;
    cout << "Enter two coded numbers: " <<endl;
    cin >> num1 >> num2;

    hour1 = num1 / 100;
    minuets1 = num1 % 100;
    hour2 = num2 / 100;
    minuets2 = num2 % 100;

    if ((hour1 >= 24 || minuets1 >= 60) || (hour2 >= 24 || minuets2 >= 60)) {
        cout << "Invalid format of one of at least one of the numbers!" << endl;
    }
    else {
        int subtractHour = abs(hour1 - hour2);
        int subtractMinuets = abs(minuets1 - minuets2);
        // The situation when the subtraction of hours is bigger than 12
        if (subtractHour > 12) {
            if (hour1 > hour2) {
                subtractHour = (24 - hour1) + hour2;
            }
            else {
                subtractHour = (24 - hour2) + hour1;
            }
        }
        //The situation when subtraction of hours is less than 10
        if (subtractHour < 10) {
            if (subtractMinuets == 0) {
                cout << "0" << subtractHour << "0" << subtractMinuets << endl;
            }
            else {
                cout << "0" << subtractHour << subtractMinuets << endl;
            }
        }
        //Default situation
        else {
            cout << subtractHour << subtractMinuets << endl;
        }
    }

    //--------------------------------------------------------------------------------------------
    //Task 2
    //--------------------------------------------------------------------------------------------
    int number1, number2;
    bool isTrue = false;
    cout << "Enter two numbers :" << endl;
    cin >> number1 >> number2;

    for (int i = 2; i < number1 / 2; ++i) {
        //Finding dividers of the first number
        if(number1 % i == 0) {
            for (int j = 0; j < number2 / 2; ++j) {
                //Checking if the pow of the divider of the first number is a divider of the second one
                if(number2 % (i * i) == 0) {
                    isTrue = true;
                    cout << "YES" << endl;
                    break;
                }
            }
        }
    }
    if (!isTrue) {
       cout << "NO" << endl;
    }

    //--------------------------------------------------------------------------------------------
    //Task 3
    //--------------------------------------------------------------------------------------------
    bool secondHand, AC, willBuy;
    int power, mileage, carPrice;
    cout << "Is the car old? (0 for NO, 1 for YES): ";
    cin >> secondHand;
    cout << "Does the car has AC? (0 for NO, 1 for YES): ";
    cin >> AC;
    cout << "Power of the car (hp): ";
    cin >> power;
    cout << "Mileage of the car (km): ";
    cin >> mileage;
    cout << "Price of the car (lv): ";
    cin >> carPrice;
    willBuy = (secondHand == true && ((AC == true && mileage < 115000 && power >= 70 && carPrice <=6000) ||
            (AC == false && mileage < 180000 && power >= 60 && carPrice <= 2000))) ||
                    (secondHand == false && (power >= 70 && power <= 90) && carPrice <= 25000);
    cout << "Will Traicho buy the car? " << (willBuy ? " yes" : " no") <<endl;


    //--------------------------------------------------------------------------------------------
    //Task 4
    //--------------------------------------------------------------------------------------------
    int people;
    double ticketPrice, discount = 0, finalTax;
    cout << "Enter first the cout of visitors and then the visit tax: " << endl;
    cin >> people >> ticketPrice;
    if (people >= 5 && people <= 10) {
        discount = 0.05;
    }
    else if (people > 10 && people <= 20) {
        discount = 0.1;
    }
    else if (people > 20) {
        discount = 0.15;
    }
    finalTax = (people * ticketPrice);
    cout << "The finall tax you have to pay is: " << finalTax - (finalTax * discount) << endl;

    //--------------------------------------------------------------------------------------------
    //Task 5
    //--------------------------------------------------------------------------------------------
    int number5;
    cout << "Enter a number to generate a sequence: ";
    cin >> number5;
    for (int i = 1; i <= number5; i++) {
        for (int j = i; j >= 1; j--) {
            cout << i << " ";
        }
    }


    return 0;
}
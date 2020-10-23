#include <iostream>
#include <cmath>

using namespace std;

int main() {
    //--------------------------------------------------------------------------------------------
    //WEEK 2
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    //Task 1
    //--------------------------------------------------------------------------------------------
    int year;
    cin >> year;

    if(year % 400 == 0){
        cout << "leap." << endl;
    }
    else if(year % 4 == 0 && year % 100 != 0){
        cout << "leap." << endl;
    }
    else {
        cout << "Not leap." << endl;
    }


    //--------------------------------------------------------------------------------------------
    //Task 2
    //--------------------------------------------------------------------------------------------
    char sym;
    cin >> sym ;

    if(sym >= 'a' && sym <='z'){
        cout << "The upper case character corresponding to is: " << char(sym - ('a' - 'A')) << endl;
    }
    else if(sym >= 'A' && sym <='Z'){
        cout << "The lower case character corresponding to is: " << char(sym + ('a' - 'A')) << endl;
    }
    else {
        cout << "This symbol is not a letter" << endl;
    }

    //--------------------------------------------------------------------------------------------
    //Task 3
    //--------------------------------------------------------------------------------------------
    int month;
    cin >> month;
    switch (month){
        case 12: case 1: case 2: cout << "The season is winter!" <<endl; break;
        case 3: case 4: case 5: cout << "The season is spring!" <<endl; break;
        case 6: case 7: case 8: cout << "The season is summer!" <<endl; break;
        case 9: case 10: case 11: cout << "The season is autumn!" <<endl; break;
        default: cout << "Incorrect month" << endl;
    }

    //--------------------------------------------------------------------------------------------
    //Task 4
    //--------------------------------------------------------------------------------------------
    int a, b, c, D, x1, x2;
    cin >> a >> b >> c;

    D = (b * b) - (4 * a * c);

    if(D < 0) {
        cout << "NO" <<endl;
    }
    else if(D == 0) {
        x1 = (-b) / 2 * a;
        cout << x1 << endl;
    }
    else {
        x1 = (-b + sqrt(D)) / 2 * a;
        x2 = (-b - sqrt(D)) / 2 * a;
        cout << x1 << " " << x2 << endl;
    }

    //--------------------------------------------------------------------------------------------
    //Task 5
    //--------------------------------------------------------------------------------------------
    int month1, year1;
    cin >> month1 >> year1;

    switch (month1) {
        case 1: case 5: case 3: case 7: case 8: case 10: case 12: cout << 31 << endl; break;
        case 4: case 6: case 9: case 11: cout << 30 <<endl; break;
        case 2:
            if(year1 % 400 == 0){
                cout << 29 <<endl;
            }
            else if(year1 % 4 == 0 && year1 % 100 != 0){
                cout << 29 <<endl;
            }
            else {
                cout << 28 <<endl;
            }
            break;
        default: cout << "Invalid parameters!" << endl;
    }

    //--------------------------------------------------------------------------------------------
    //Task 6
    //--------------------------------------------------------------------------------------------
    double price;
    int USBports, RAM;
    bool SSD;

    cin >> price >> USBports >> RAM >> SSD;

    bool statement1, statement2;

    statement1 = (price >= 1000 && price <= 1500) && USBports >= 3 && RAM >= 8 && SSD == 1;
    statement2 = (SSD == 0 || RAM <= 8) && price <= 800;

    if(statement1 || statement2){
        cout << "Yes, Traicho will buy a new laptop!" << endl;
    }
    else{
        cout << "No, Traicho will not buy a new laptop!" << endl;
    }

    //--------------------------------------------------------------------------------------------
    //Task 7
    //--------------------------------------------------------------------------------------------
    int number, firstNum, secondNum, thirdNum, fourthNum;
    cin >> number;
    firstNum = number / 1000;
    secondNum = (number / 100)  % 10;
    thirdNum = (number / 10)  % 10;
    fourthNum = number % 10;
    if(number >= 1000 && number <= 9999) {
        if (firstNum % 2 == 1 && firstNum > secondNum && firstNum > thirdNum && firstNum > fourthNum) {
            cout << "Yes" <<endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    else {
        cout << "invalid number" << endl;
    }

    //--------------------------------------------------------------------------------------------
    //Bonus 0
    //--------------------------------------------------------------------------------------------
    int tomatoes, peppers, carrots, olives, potatoes, flavoringMl;
    bool Friend = 0;
    cin >> tomatoes >> peppers >> carrots >> olives >> potatoes >> flavoringMl;
    if(tomatoes > 1){
        Friend = 1;
    }
    bool studentSalad = tomatoes >= 1 && peppers >= 2 && carrots >= 4 && olives >= 3 && potatoes >= 3 && flavoringMl >= 150;
    bool studentSoup = tomatoes >= 2 && peppers >= 3 && carrots >= 5 && olives >= 6 && potatoes >= 10 && flavoringMl >= 200;
    bool studentGuvech = tomatoes >= 5 && peppers >= 6 && carrots >= 12 && olives >= 7 && potatoes >= 12 && flavoringMl >= 300;
    if(studentGuvech || studentSalad || studentSoup){
        cout << "Yes, Traich will eat" << endl;
    }else {
        cout << "No, Traicho will continue studying in order to have money for food xD" << endl;
    }

    //--------------------------------------------------------------------------------------------

    return 0;

}

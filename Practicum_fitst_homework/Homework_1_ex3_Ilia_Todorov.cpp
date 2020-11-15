#include <iostream>
#include <cmath>

using namespace std;

// Function for finding the decimal value of the every symbol.
int convert(char toBeConverted) {
    int result;

    switch (toBeConverted) {
        case '0': result = 0;
            break;
        case 'a': result = 1;
            break;
        case 'b': result = 2;
            break;
        case 'c': result = 3;
            break;
        case 'd': result = 4;
            break;
        case 'e': result = 5;
            break;
        case 'f': result = 6;
            break;
        case 'g': result = 7;
            break;
        case 'h': result = 8;
            break;
        case 'i': result = 9;
            break;
        case 'j': result = 10;
            break;
        case 'k': result = 11;
            break;
        case 'l': result = 12;
            break;
        case 'm': result = 13;
            break;
        default: return 0;
    }
    return result;
}


int MaxLength = 100;

int main() {
    char date[MaxLength], dayChar[MaxLength], monthChar[MaxLength], yearChar[MaxLength], convertedDec[MaxLength];
    int /*Input*/ decimalToConvert, i = 0, dotCounter = 0, dateCounter = 0, monthCounter = 0,
            yearCounter = 0, day = 0, month = 0, year = 0, conv = 1,
    /*Checking the day of week*/ oddDaysPerCentuary = 0, oddDaysPerMonth = 0, allOddDays = 0,
            remainingYears, remainingLeapYears,
    /*Converting the decimal number to fourteenth number system on the Milky way*/
    reminder = 0, counterDec = 0;
    bool /*Validation*/ invalidData = false, /*Checking the day of week*/ leap, isWorkingDay;

    //***************************************************************************************
    // Input
    //***************************************************************************************
    cout << "Enter a date in FOURTEENTH number system on the Milky way (in format: DAY.MONTH.YEAR): ";
    while (cin.peek() != '\n') {
        cin >> date[i];
        i++;
    }
    for (int j = 0; j < i; ++j) {
        if (date[j] == '.') {
            dotCounter++;
            continue;
        }
        // Check if the letter is in fourteenth number system on the Milky way
        if (!(int(date[j]) >= 97 && int(date[j]) <= 109)) {
            if (date[j] != '0') {
                invalidData = true;
                break;
            }
        }
        if (dotCounter == 0){
            dayChar[dateCounter] = date[j];
            dateCounter++;
        }
        else if (dotCounter == 1) {
            monthChar[monthCounter] = date[j];
            monthCounter++;
        }
        else if (dotCounter == 2) {
            yearChar[yearCounter] = date[j];
            yearCounter++;
        }
        else {
            invalidData = true;
        }
    }
    cout << "Enter a decimal which will be converted to fourteenth number system on the Milky way: ";
    cin >> decimalToConvert;
    if (cin.fail()) {
        invalidData = true;
    }

    //***************************************************************************************
    // Validation
    //***************************************************************************************
    if (invalidData) {
        cout << "Invalid data!" << endl;
        return 0;
    }


    //***************************************************************************************
    // Converting the date to decimal number system
    //***************************************************************************************
    for (int j = 0; j < dateCounter; ++j) {
        day += convert(dayChar[j]) * pow(14, (dateCounter - conv));
        conv++;
    }
    conv = 1;
    for (int j = 0; j < monthCounter; ++j) {
        month += convert(monthChar[j]) * pow(14, (monthCounter - conv));
        conv++;
    }
    conv = 1;
    for (int j = 0; j < yearCounter; ++j) {
        year += convert(yearChar[j]) * pow(14, (yearCounter - conv));
        conv++;
    }

    //***************************************************************************************
    // Checking the day of week
    //***************************************************************************************

    //Boolean sentence in order to check if the year is leap or not.
    leap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    //Getting the last two digits of the complete years. | eg. 1953 -> 53
    remainingYears = (year % 100) - 1;
    //Getting the leap years out of the last two digits of the complete years. | eg. 53 / 4 = 13
    remainingLeapYears = remainingYears / 4;

    //***************************************************************************************
    // Validation 2
    bool invalid = !((month >= 1 && month <= 12) && (day >= 1 && day <= 31)) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
                   || ((leap && month == 2 && day > 29) || (!leap && month == 2 && day > 28));
    if(invalid) {
        cout << "Invalid data!" << endl;
        return 0;
    }
    //***************************************************************************************

    //Setting values for the odd days (for every month up to the current/incomplete month) and adding them to the whole odd days.
    //eg. January -> 31 days => odd days for Jan. = 31 % 7 = 3
    for (int j = 1; j < month; ++j) {
        switch (j) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                oddDaysPerMonth = 3;
                break;
            case 4: case 6: case 9: case 11:
                oddDaysPerMonth = 2;
                break;
            case 2:
                if (leap) {
                    oddDaysPerMonth = 1;
                }
                else {
                    oddDaysPerMonth = 0;
                }
                break;
            default:
                cout << "Invalid data!" << endl;
                break;
        }
        allOddDays += oddDaysPerMonth;
    }
    //Adding the odd days for the all leap years and normal years to the whole odd days.
    //Normal year has 365 days and if we divide it by 7 we will get 1 (the odd days for a normal year).
    //Leap year has 366 days and if we divide it by 7 we will get 2 (the odd days for a leap year).
    //Also we consider the remaining days of the incomplete month as odd so we add them too.
    allOddDays += (2 * remainingLeapYears) + (remainingYears - remainingLeapYears) + day;

    //Setting values for the odd days for a century.
    //100 years consists of 24 leap years and 76 normal years (because 100 is not a leap year)
    //76 normal years have 1 odd day each.
    //24 leap years have 2 odd days each.
    //All makes 124 odd days, which % 7 gives us 5 odd days per 100 years
    //So 200 years has 10, but %7 gives us 3 odd days => 300 years has 1 odd day.
    int helpYear = year, helpYear2 = year;
    do {
        if (helpYear / 400 == 1) {
            helpYear -= 400;
            break;
        }
        helpYear -= 400;
    } while (helpYear > 0);
    if (helpYear / 100 == 1) {
        oddDaysPerCentuary = 5;
        allOddDays += oddDaysPerCentuary;

    }
    else if (helpYear / 200 == 1) {
        oddDaysPerCentuary = 3;
        allOddDays += oddDaysPerCentuary;

    }
    else if (helpYear / 300 == 1) {
        oddDaysPerCentuary = 1;
        allOddDays += oddDaysPerCentuary;
    }
    else {
        oddDaysPerCentuary = 0;
        allOddDays += oddDaysPerCentuary;
    }
    //Getting the actual odd days by %7 aut the all of them.
    allOddDays %= 7;
    if(year == 2000) {
        if(allOddDays != 0) {
            allOddDays -= 1;
        }
        else {
            allOddDays += 6;
        }
    }
    //Displaying the weekday of the next day
    switch (allOddDays) {
        case 0: case 6:
            isWorkingDay = false;
            break;
        case 1: case 2: case 3: case 4: case 5:
            isWorkingDay = true;
            break;
        default: return 0;
    }

    //***************************************************************************************
    // Converting the decimal number to fourteenth number system on the Milky way
    //***************************************************************************************
    int helpConvert = decimalToConvert;
    while (helpConvert != 0) {
        reminder = helpConvert % 14;
        switch (reminder) {
            case 0: convertedDec[counterDec] = '0';
                break;
            case 1: convertedDec[counterDec] = 'a';
                break;
            case 2: convertedDec[counterDec] = 'b';
                break;
            case 3: convertedDec[counterDec] = 'c';
                break;
            case 4: convertedDec[counterDec] = 'd';
                break;
            case 5: convertedDec[counterDec] = 'e';
                break;
            case 6: convertedDec[counterDec] = 'f';
                break;
            case 7: convertedDec[counterDec] = 'g';
                break;
            case 8: convertedDec[counterDec] = 'h';
                break;
            case 9: convertedDec[counterDec] = 'i';
                break;
            case 10: convertedDec[counterDec] = 'j';
                break;
            case 11: convertedDec[counterDec] = 'k';
                break;
            case 12: convertedDec[counterDec] = 'l';
                break;
            case 13: convertedDec[counterDec] = 'm';
                break;
            default: return 0;
        }
        helpConvert /= 14;
        counterDec++;
    }
    // Reversing the array in order to get the right value of the decimal number(converted)
    int helpReverse1 = 0, helpReverse2 = counterDec - 1;
    while (helpReverse1 < helpReverse2) {
        char temp = convertedDec[helpReverse1];
        convertedDec[helpReverse1] = convertedDec[helpReverse2];
        convertedDec[helpReverse2] = temp;
        helpReverse1++;
        helpReverse2--;
    }

    //***************************************************************************************
    // Displaying the result
    //***************************************************************************************
    if (isWorkingDay) {
        cout << "No, ";
    }
    else {
        cout << "Yes, ";
    }
    cout << day << ".";
    cout << month << ".";
    cout << year;
    if (isWorkingDay) {
        cout << " is a working day. ";
    }
    else {
        cout << " isn't a working day. ";
    }
    cout << decimalToConvert << " -> ";
    for (int j = 0; j < counterDec; ++j) {
        cout << convertedDec[j];
    }
    cout << endl;
    return 0;
}
    

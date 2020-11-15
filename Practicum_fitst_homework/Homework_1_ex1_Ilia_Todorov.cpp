#include <iostream>

using namespace std;

int main() {
    //Find the next day of any date.
    int day, month, year;
    cin >> day >> month >> year;
    bool invalid, leap;

    leap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    invalid = !((year >= 1900 && year <= 2100) && (month >= 1 && month <= 12) && (day >= 1 && day <= 31))
              || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
              || ((leap && month == 2 && day > 29) || (!leap && month == 2 && day > 28));


    //Validation.
    if (invalid) {
        cout << "Invalid data!" << endl;
    }
        //Actual code.
    else {
        int oddDaysPerCentuary = 0, oddDaysPerMonth = 0, allOddDays = 0, remainingYears, remainingLeapYears;
        //Getting the last two digits of the complete years. | eg. 1953 -> 53
        remainingYears = (year % 100) - 1;
        //Getting the leap years out of the last two digits of the complete years. | eg. 53 / 4 = 13
        remainingLeapYears = remainingYears / 4;

        //Setting values for the odd days (for every month up to the current/incomplete month) and adding them to the whole odd days.
        //eg. January -> 31 days => odd days for Jan. = 31 % 7 = 3
        for (int i = 1; i < month; ++i) {
            switch (i) {
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
        if (year < 2000) {
            //1900 - 1999
            oddDaysPerCentuary = 1;
            allOddDays += oddDaysPerCentuary;

        }
        else if (year < 2100) {
            //2000 - 2099
            oddDaysPerCentuary = 0;
            allOddDays += oddDaysPerCentuary;

        }
        else {
            //2100
            oddDaysPerCentuary = 5;
            allOddDays += oddDaysPerCentuary;
        }
        //Getting the actual odd days by %7 aut the all of them.
        allOddDays %= 7;
        if(year == 2000) {
            if (allOddDays != 0) {
                allOddDays -= 1;
            }
            else {
                allOddDays += 6;
            }
        }

        //Displaying the weekday of the next day
        switch (allOddDays) {
            case 0:
                cout << "Monday, " ;
                break;
            case 1:
                cout << "Tuesday, ";
                break;
            case 2:
                cout << "Wednesday, ";
                break;
            case 3:
                cout << "Thursday, ";
                break;
            case 4:
                cout << "Friday, ";
                break;
            case 5:
                cout << "Saturday, ";
                break;
            case 6:
                cout << "Sunday, ";
                break;
        }

        //Solving the case in which it is the last day of the month or year and setting the day to the next
        switch (month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                if (day == 31) {
                    day = 1;
                    if(month < 12){
                        month += 1;
                    }
                    else {
                        month = 1;
                        year += 1;
                    }

                }
                else {
                    day += 1;
                }
                break;
            case 4: case 6: case 9: case 11:
                if (day == 30) {
                    day = 1;
                    if(month < 12){
                        month += 1;
                    }
                    else {
                        month = 1;
                        year += 1;
                    }
                }
                else {
                    day += 1;
                }
                break;
            case 2:
                if (leap) {
                    if (day == 29) {
                        day = 1;
                        if(month < 12){
                            month += 1;
                        }
                        else {
                            month = 1;
                            year += 1;
                        }
                    }
                    else {
                        day += 1;
                    }
                }
                else {
                    if (day == 28) {
                        day = 1;
                        if(month < 12){
                            month += 1;
                        }
                        else {
                            month = 1;
                            year += 1;
                        }
                    }
                    else {
                        day += 1;
                    }
                }
                break;
            default:
                cout << "Invalid data!" << endl;
                break;
        }


        //Displaying the next day.
        cout << day << ", ";
        //Displaying the month.
        switch (month){
            case 1:
                cout << "January, " ;
                break;
            case 2:
                cout << "February, ";
                break;
            case 3:
                cout << "March, ";
                break;
            case 4:
                cout << "April, ";
                break;
            case 5:
                cout << "May, ";
                break;
            case 6:
                cout << "June, ";
                break;
            case 7:
                cout << "July, ";
                break;
            case 8:
                cout << "August, ";
                break;
            case 9:
                cout << "September, ";
                break;
            case 10:
                cout << "October, ";
                break;
            case 11:
                cout << "November, ";
                break;
            case 12:
                cout << "December, ";
                break;
        }
        //Displaying the year.
        cout << year << endl;

    }





    return 0;
}
    

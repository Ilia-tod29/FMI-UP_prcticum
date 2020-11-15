#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int number, prev = 1, answ, answEq = 0;
    cin >> number;

    //Validation
    if(number < 0) {
        cout << "Invalid data!" << endl;
    }
    else {
        //Check whether the number is power of two or not (using its binary value).
        //YES
        if((number & number - 1) || number < 1){
            cout << "Not power of 2" << endl;
            //Solving the problem with number 0.
            if (number == 0) {
                answ = 0;
            }
            //Finding the closest power of 5.
            else {
                for (int i = 0; i < number; i++) {
                    answ = i;
                    if (abs(number - prev) == abs(number - pow(5, i + 1))) {
                        answEq = i + 1;
                        break;
                    } else if (abs(number - prev) < abs(number - pow(5, i + 1))) {
                        break;
                    }
                    prev = pow(5, i + 1);
                }
            }
            cout << "Closest power of 5 is: ";
        }
        //NO
        else {
            cout << "Power of 2" << endl;
            //Finding the closest power of 3.
            for (int i = 0; i < number; i++) {
                answ = i;
                if(abs(number - prev) == abs(number - pow(3, i + 1))){
                    answEq = i + 1;
                    break;
                }
                else if(abs(number - prev) < abs(number - pow(3, i + 1))){
                    break;
                }
                prev = pow(3, i + 1);
            }
            cout << "Closest power of 3 is: ";
        }
        //Displaying the answer.
        if(answEq != 0){
            cout << answEq << ", ";
        }
        cout << answ << endl;
    }



    return 0;
}

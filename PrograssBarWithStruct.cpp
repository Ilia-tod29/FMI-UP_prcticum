#include <iostream>
#include <chrono>
#include <thread>

using std::cin;
using std::cout;
using std::endl;

struct PrograssBar {
    bool indicator;
    short int arrLength;
    float currentProgress;
    char start, end, progress, empty;
    PrograssBar() {
        this->arrLength = 0;
        this->currentProgress = 0;
        this->indicator = 0;
        this->start = '[';
        this->end = ']';
        this->progress = '>';
        this->empty = '-';
    }

    void loadBar (float change) {
        char* arr = new char[this->arrLength];
        while(this->currentProgress <= 1.0) {
            cout << int(this->currentProgress * 100) << "% -> " << this->start;
            int position = this->currentProgress * this->arrLength;
            for (int i = 0; i < this->arrLength; ++i) {
                if (i <= position) {
                    arr[i] = this->progress;
                    cout << arr[i];
                    if (i == position) {
                        if (this->indicator) {
                            cout << int(this->currentProgress * 100) << "%";
                        }
                    }
                } else if (i > position) {
                    arr[i] = this->empty;
                    cout << arr[i];
                }
            }
            cout << this->end << "\r";
            std::cout.flush();
            this->currentProgress += change;
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
        delete[] arr;
    }



    void input(PrograssBar &prBar){
        cout << "Enter array length: ";
        cin >> prBar.arrLength;
        cout << "Enter current progress: ";
        cin >> prBar.currentProgress;
        cout << "Enter indicator (0/1): ";
        cin >> prBar.indicator;
        cout << "Enter start element: ";
        cin >> prBar.start;
        cout << "Enter end element: ";
        cin >> prBar.end;
        cout << "Enter progress element: ";
        cin >> prBar.progress;
        cout << "Enter empty element: ";
        cin >> prBar.empty;
    }
};

int main(){
    PrograssBar prb;
    prb.input(prb);
    prb.loadBar(0.01);
    return 0;
}
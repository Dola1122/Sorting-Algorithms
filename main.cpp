#include <iostream>
#include "sortlib.h"

using namespace sortlib;
using namespace std;

int main() {
    double numbers[] = {5.3, 2.2, 4.9, 3.23, 0.1, 10.3, 8.1};
    string names[] = {"mohamed", "mai", "ahmed", "nour", "sara", "adam", "aya"};

    int n1 = sizeof(numbers) / sizeof(numbers[0]);
    int n2 = sizeof(names) / sizeof(names[0]);


    // test your sorting algorithms here
    // // // // // // // // // // //

    shellSort(numbers, n1);
    shellSort(names, n2);

    // // // // // // // // // // //



    for (auto i: numbers)
        cout << i << "  ";
    cout << endl;

    for (auto i: names)
        cout << i << "  ";
    cout << endl;

    return 0;
}

#include <iostream>
#include "sortlib.h"

using namespace sortlib;
using namespace std;

int main()
{
    double numbers[] = {5.3, 2.2, 4.9, 3.23, 0.1, 10.3, 8.1};
    string names[] = {"mohamed", "mai", "ahmed", "nour", "sara", "adam", "aya"};

    int sze1 = sizeof(numbers) / sizeof(numbers[0]);
    int sze2 = sizeof(names) / sizeof(names[0]);

//    insertionSort(numbers,sze1);
//    insertionSort(names,sze2);

//    selectionSort(numbers,sze1);
//    selectionSort(names,sze2);

//    bubbleSort(numbers, sze1);
//    bubbleSort(names, sze2);

//    shellSort(numbers, sze1);
//    shellSort(names, sze2);

    mergeSort(numbers,0,sze1 - 1);
    mergeSort(names,0,sze2 - 1);

    print(numbers,sze1);
    print(names,sze2);

    return 0;
}
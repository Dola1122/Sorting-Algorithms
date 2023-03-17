#ifndef SORTING_ALGORITHMS_SORTLIB_H
#define SORTING_ALGORITHMS_SORTLIB_H
namespace sortlib {
    // swap two elements by refrence
    template<typename T>
    void swap(T &a, T &b) {
        T temp = a;
        a = b;
        b = temp;
    }

    template<typename T>
    void insertionSort(T arr[], int n) {

        // loop over every element in the array starting from the second element
        for (int i = 1; i < n; i++) {

            // put every element in its sorted position on the left side
            // ( left : sorted elements | right : unsorted elements )
            int k = i;
            while (arr[k] < arr[k - 1] && k > 0) {
                swap(arr[k], arr[k - 1]);
                k--;
            }
        }
    }

    template<typename T>
    void shellSort(T arr[], int n) {

        // loop for each gap , gap start from n/2 end when gap = 0
        for (int gap = n / 2; gap > 0; gap /= 2) {

            // loop over each element starting from gap and to the end of the array
            for (int i = gap; i < n; i++) {

                // put the element in the (i)th position in its correct position
                for (int j = i; j >= gap && arr[j - gap] > arr[j]; j -= gap) {
                    swap(arr[j - gap], arr[j]);
                }
            }
        }
    }

}
#endif //SORTING_ALGORITHMS_SORTLIB_H

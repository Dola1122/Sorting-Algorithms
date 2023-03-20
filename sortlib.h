#ifndef SORTING_ALGORITHMS_SORTLIB_H
#define SORTING_ALGORITHMS_SORTLIB_H
namespace sortlib
{

    // print array
    template <typename T>
    void print(T arr[], int n)
    {

        for (int i = 0; i < n; i++)
        {
            std::cout << arr[i] << "  ";
        }
        std::cout << std::endl;
    }

    // swap two elements by refrence
    template <typename T>
    void swap(T &a, T &b)
    {
        T temp = a;
        a = b;
        b = temp;
    }

    template <typename T>
    void insertionSort(T arr[], int n)
    {

        // loop over every element in the array starting from the second element
        for (int i = 1; i < n; i++)
        {

            // put every element in its sorted position on the left side
            // ( left : sorted elements | right : unsorted elements )
            int k = i;
            while (arr[k] < arr[k - 1] && k > 0)
            {
                swap(arr[k], arr[k - 1]);
                k--;
            }
        }
    }

    template <typename T>
    void selectionSort(T arr[], int n)
    {
        int minIndex;

        // assign the current index to the minimum index
        for (size_t i = 0; i < n - 1; i++)
        {
            minIndex = i;

            for (size_t j = i + 1; j < n; j++)
            {
                // if there is an index less than the current minimum update the minimum index with it
                if (arr[j] < arr[minIndex])
                {
                    minIndex = j;
                }
            }

            // swap the minimum item with the item at the current index (i)
            swap(arr[minIndex], arr[i]);
        }
    }

    template <typename T>
    void bubbleSort(T arr[], int n)
    {

        // loop through all array elements
        for (int i = 0; i < n - 1; i++)
        {

            // last element is already sorted
            for (int j = 0; j < n - i - 1; j++)
            {

                // swap if the element found is greater than the next element
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    template <typename T>
    void shellSort(T arr[], int n)
    {

        // loop for each gap , gap start from n/2 end when gap = 0
        for (int gap = n / 2; gap > 0; gap /= 2)
        {

            // loop over each element starting from gap and to the end of the array
            for (int i = gap; i < n; i++)
            {

                // put the element in the (i)th position in its correct position
                for (int j = i; j >= gap && arr[j - gap] > arr[j]; j -= gap)
                {
                    swap(arr[j - gap], arr[j]);
                }
            }
        }
    }

    void countSort(int arr[], int n)
    {
        // get the max element in the array
        int max = *std::max_element(arr, arr + n);
        // create array to store the count of each element
        int count[max];
        // create array to store the sorted elements
        int sorted[n];

        // initialize the count array with 0
        for (size_t i = 0; i <= max; i++)
        {
            count[i] = 0;
        }
        // count the number of occurrences of each element and store it in the count array
        for (int i = 0; i < n; i++)
        {
            count[arr[i]]++;
        }
        // calculate the cumulative sum of the count array
        for (int i = 1; i <= max; i++)
        {
            count[i] += count[i - 1];
        }
        // put the elements in the sorted array in their correct position
        for (int i = n - 1; i >= 0; i--)
        {
            sorted[count[arr[i]] - 1] = arr[i];
            // decrement the count of the element after place it in the sorted array
            count[arr[i]]--;
        }
        // copy the sorted array to the original array
        for (int i = 0; i < n; i++)
        {
            arr[i] = sorted[i];
        }
    }

    template <typename T>
    void merge(T arr[], int l, int m, int r)
    {

        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;

        // Create two arrays
        T lArry[n1], rArry[n2];

        // Copy data to arrays Left and Right
        for (i = 0; i < n1; i++)
            lArry[i] = arr[l + i];

        for (j = 0; j < n2; j++)
            rArry[j] = arr[m + 1 + j];

        i = 0;
        j = 0;
        k = l;

        // loop through all array elements
        while (i < n1 && j < n2)
        {
            if (lArry[i] <= rArry[j])
            {
                arr[k] = lArry[i];
                i++;
            }
            else
            {
                arr[k] = rArry[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of Left
        while (i < n1)
        {
            arr[k] = lArry[i];
            i++;
            k++;
        }

        // Copy the remaining elements of Right
        while (j < n2)
        {
            arr[k] = rArry[j];
            j++;
            k++;
        }
    }

    template <typename T>
    void mergeSort(T arr[], int l, int r)
    {

        if (l < r)
        {
            int m = l + (r - l) / 2;

            // Sort first and second halves
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);

            // Merge the sorted halves
            merge(arr, l, m, r);
        }
    }
}

#endif // SORTING_ALGORITHMS_SORTLIB_H

#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

void displayResult(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;

    return;
}

void insertion(int arr[], int* begin, int* end)
{
    // get the left and right index of subarray to be sorted
    int left = begin - arr;
    int right = end - arr;

    for(int i = left + 1; i <= right; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements of array[0...i-1], that are greater than key, to one position ahead of their current position
        while(j >= left && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    return;
}

// a function that find the middle of the values pointed by the pointers x, y, z and return the pointer
int *MedianOfThree(int *x, int *y, int *z)
{
    if (*x < *y && *y < *z)
    {
        return (y);
    }

    if (*x < *z && *z <= *y)
    {
        return (z);
    }

    if (*y <= *x && *x < *z)
    {
        return (x);
    }

    if (*y < *z && *z <= *x)
    {
        return (z);
    }

    if (*z <= *x && *x < *y)
    {
        return (x);
    }

    if (*z <= *y && *y <= *x)
    {
        return (y);
    }

    return 0;
}

// function to partition the array and return partition point
int* partition(int arr[], int low, int high)
{
    // pivot
    int pivot = arr[high];
    int i = low - 1; // index of smaller element

    for(int j = low; j <= high - 1; j++)
    {
        // if the current element smaller than or equal to pivot
        if(arr[j] <= pivot)
        {
            // increment index of smaller element
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);

    return(arr+i+1);
}

// a utility function to perform intro sort
void utility(int arr[], int *begin, int *end, int depthLimit)
{
    // count the number of elements
    int size = end - begin;

    // if the partition size less than 16 then do insertion sort
    if (size < 16)
    {
        insertion(arr, begin, end);
        return;
    }

    // if the depth is zero use heapsort
    if (depthLimit == 0)
    {
        make_heap(begin, end + 1); // function comes from <algorithm>
        sort_heap(begin, end + 1); // function comes from <algorithm>

        return;
    }

    // else use a median of three concept to find a good pivot
    int *pivot = MedianOfThree(begin, begin + size / 2, end);

    // swap the values pointed by the pointers
    swap(pivot, end);

    // perform quick sort
    int *partitionPoint = partition(arr, begin - arr, end - arr);
    utility(arr, begin, partitionPoint - 1, depthLimit - 1);
    utility(arr, partitionPoint + 1, end, depthLimit - 1);

    return;
}

void IntroSort(int arr[], int *begin, int *end)
{
    int depthLimit = 2 * log(end - begin);

    // perform a recursive introsort
    utility(arr, begin, end, depthLimit);

    return;
}

int main()
{
    int arr[] = { 3, 1, 23, -9, 233, 23, -313, 32, -9 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // pass the array, the pointer to the first element and the pointer to the last element
    IntroSort(arr, arr, arr+n-1);
    displayResult(arr, n);

    return(0);
}

// source: https://www.geeksforgeeks.org/introsort-or-introspective-sort/
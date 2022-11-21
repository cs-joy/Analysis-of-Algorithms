#include<iostream>

using namespace std;

/*

@ Time complexity:
  @ Best - O(n*log n)
  @ Worst - O(n^2)
  @ Average - O(n*log n)
@ Space complexity - O(log n)
@ Stability - No

*/

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partitionPoint(int arr[], int low, int high)
{
    // rightmost element of arr
    int pivotElement = arr[high];

    // pointer for greater element
    int greaterElement = low - 1;

    // traverse each element of the arr
    // compare then with the pivot
    for(int j = low; j < high; j++)
    {
        if(arr[j] <= pivotElement)
        {
            // if element is smaller than pivot is found
            // swap it with the greater element  pointed
            greaterElement++;

            // swap element at greaterElement with element at j
            swap(&arr[greaterElement], &arr[j]);
        }
    }

    // swap pivot with greater element at greaterElement
    swap(&arr[greaterElement+1], &arr[high]);

    // return partition point
    return(greaterElement+1);
}

void quickSort(int ar[], int low, int high)
{
    if(low < high)
    {
        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pp = partitionPoint(ar, low, high);

        // recursive call on the left of the pivot
        quickSort(ar, low, pp-1);

        // recursive call on the right of the pivot
        quickSort(ar, pp+1, high);
    }
}

int main()
{
    int data[] = { 3, 1, 0, 6, 9, 4, 7, 10, 2 };
    int n = sizeof(data) / sizeof(data[0]);

    int low = 0;
    int high = n - 1;
    quickSort(data, low, high);

    // print
    for(int i=0; i < n; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
    
    return(0);
}

// ref: https://en.wikipedia.org/wiki/Quicksort
#include<iostream>

using namespace std;

/*
@ Time complexity: O(N^2)
@ Auxiliary Space: O(1)
@ Worst-case: O(N^2) comparisons and swaps
@ Best-case: O(N^2) comparisons and O(1) swaps
@ Average: O(N) comparisons and swaps
*/

void insertionSorting(int arr[], int n)
{
    int key, j;
    for(int i = 1; i<n; i++)
    {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    // print result
    for(int i = 0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int unsortedArr[] = { 2, 0, 1, 4, 6, 3, 9, 5 };
    int n = sizeof(unsortedArr) / sizeof(unsortedArr[0]);

    insertionSorting(unsortedArr, n);

    return(0);
}

// ref: https://en.wikipedia.org/wiki/Insertion_sort
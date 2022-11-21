#include<iostream>

using namespace std;

void swap(int* n1, int* n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void selectionSort(int arr[], int n)
{
    for(int step = 0; step < n; step++)
    {
        int minIndex = step;
        for(int i = step + 1; i<n; i++)
        {
            // To sort in descending order, change > to < in this line
            // select the minimum element in each loop
            if(arr[i] < arr[minIndex])
            {
                minIndex = i;
            }
        }

        // put min at the correct position
        swap(&arr[minIndex], &arr[step]);
    }
}

/*

@ Time complexity
  @ Best - O(n^2)
  @ Worst - O(n^2)
  @ Average - O(n^2)

@ Space complexity - O(1)
@ Stability - No

*/

int main()
{
    int data[] = { 3, 1, 0, 5, 7, 2, 9 };
    int n = sizeof(data) / sizeof(data[0]);
    selectionSort(data, n);

    // print
    for(int i = 0; i<n; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;

    return(0);
}

// ref :: https://en.wikipedia.org/wiki/Selection_sort
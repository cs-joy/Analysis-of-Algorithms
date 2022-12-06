#include<iostream>
#include<cmath>

using namespace std;

int jumpSearch(int arr[], int x, int n)
{
    // find out block size to be jumped
    int step = sqrt(n);

    // finding the block where element is present (if it is present)
    int prev = 0;
    while(arr[min(step, n)-1] < x)
    {
        prev = step;
        step += sqrt(n);

        if(prev >= n)
        {
            return -1;
        }
    }

    // doing a linear search x in block begining with prev
    while(arr[prev < x])
    {
        prev++;

        // if we reached next block or end of array, element is not present
        if(prev == min(step, n))
        {
            return -1;
        }

        // if element is found
        if(arr[prev] == x)
        {
            return(prev);
        }
    }

    return -1;
}

int main()
{
    int data[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21,34, 55, 89, 4, 233, 377, 610 };
    int search = 4;
    int size = sizeof(data) / sizeof(data[0]);
    
    int index = jumpSearch(data, search, size);
    if(index == -1)
    {
        cout << "Number " << search << " is not found!" << endl;
    } else {
        cout << "Number " << search <<" is located at index " << index << endl;
    }

    return 0;
}

/**
 * Time Complexity : O(√n) 
 * Auxiliary Space : O(1)
 * 
 * 
 * Important points: 
 

 * Works only with sorted arrays.
        * The optimal size of a block to be jumped is (√ n). This makes the time complexity of Jump Search O(√ n).
        * The time complexity of Jump Search is between Linear Search ((O(n)) and Binary Search (O(Log n)).
        * Binary Search is better than Jump Search, but Jump Search has the advantage that we traverse back only once (Binary Search may require up to O(Log n) jumps, consider a situation where the element to be searched is the smallest element or just bigger than the smallest). So, in a system where binary search is costly, we use Jump Search.
*/
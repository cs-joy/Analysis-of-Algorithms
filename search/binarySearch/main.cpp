#include<iostream>
#include<vector>

using namespace std;

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1

// Recursive Method
int binarySearch(int arr[], int low, int high, int x)
{
    if(high >= low)
    {
        int mid = low + (high - low) / 2;

        // If the element is present at the middle
        // itself
        if(arr[mid] == x)
        {
            return(mid);
        }

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if(arr[mid] > x)
        {
            return binarySearch(arr, low, mid - 1, x);
        }

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, high, x);
    }

    // We reach here when element is not
    // present in array
    return(-1);
}


// Iterative Method
void BS(vector<int> v, int data)
{
    int left = 0; int right = v.size() - 1;
    while(right-left > 1)
    {
        int mid = (right + left) / 2;
        if(v[mid] < data)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    if(v[left] == data)
    {
        cout << "\nElement found at index " << left << endl;
    }
    else if(v[right] == right)
    {
        cout << "\nElement found at index " << right << endl;
    }
    else
    {
        cout << "\nElement not found!" << endl;
    }
}

/*

  @ Time Complexity: O(log n)
  @ Auxiliary Space: O(log n)

*/

int main()
{
    int myArr[] = { 2, 3, 4, 10, 40 };
    int jAr[] = { 5, 9, 17, 23, 25, 45, 59, 63, 71, 79 };
    int n = sizeof(jAr) / sizeof(jAr[0]);
    int left = 0;
    int right = n - 1;
    int data = 60;

    // element to find out
    int x  = 4;

    int size = sizeof(myArr) / sizeof(myArr[0]);

    int l = 0; // low
    int h = size - 1; // high

    int result = binarySearch(jAr, left, right, data);

    (result == -1) ? cout << "Element is not present in array" : cout << "Element is present at index " << result;

    // BS
    vector<int> arr =  { 1, 3, 4, 5, 6 };
    int d = 5;
    BS(arr, d);


    return(0);
}

// source :: https://en.wikipedia.org/wiki/Binary_search_algorithm
#include<iostream>
#include<vector>

using namespace std;

int linearSearch(int arr[], int n, int data)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == data)
        {
            return i;
        }
    }

    return -1;
}

int RecursiveWay(int arr[], int size, int key)
{
    if(size == 0)
    {
        return -1;
    }
    else if(arr[size - 1] == key)
    {
        return(size - 1);
    }
    else
    {
        int answer = RecursiveWay(arr, size - 1, key);
        return(answer);
    }
}

int usingVector(vector<int> vr, int value)
{
    int size = vr.size();

    for(int i = 0; i < size; i++)
    {
        if(vr[i] == value)
        {
            return(i);
        }
    }

    return -1;
}

/*
@ Time Complexity: O(n)
@ Space Complexity: O(1)
*/

int main()
{
    int ar[] = { 1, 5, 3, 7, 8, 2, 3, 9, 6 };
    int n = sizeof(ar) / sizeof(ar[0]);

    int x = 2;

    int result = linearSearch(ar, n, x);
    (result == -1) ? cout << "Element is not found!\n" : cout << "Element is found at index " << result << endl;

    vector<int> var = { 1, 5, 3, 7, 8, 2, 3, 9, 6 };
    int toFind = 6;
    int r = usingVector(var, toFind);

    (r == -1) ? cout << "Element not found!\n" : cout << "Element found at index " << r << endl;

    // Recursive Way
    int rArr[] = { 3, 7, 6, 4, 9, 0, 2, 1 };
    int sizeOf_rArr = sizeof(rArr) / sizeof(rArr[0]);
    int k = 2;

    int res = RecursiveWay(rArr, sizeOf_rArr, k);
    if(res == -1)
    {
        cout << "Element not found!" << endl;
    }
    cout << "Element found at index " << res << endl;

    return 0;
}
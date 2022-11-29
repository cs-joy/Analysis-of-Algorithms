#include<iostream>
#include"introSortSpace.hpp"
#include"displaySpace.hpp"

using namespace std;
using namespace implementationIntroSort;

int main()
{
    int arr[] = { 3, 1, 23, -9, 233, 23, -313, 16, 32, -9 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // pass the array, the pointer to the first element and the pointer to the last element
    IntroSort(arr, arr, arr+n-1);
    disSpace::displayResult(arr, n);

    return(0);
}

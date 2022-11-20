#include<iostream>
#include "divideTwoSub.hpp"

using namespace std;

int main()
{
    int unsortedArray[] = { 15, 5, 24, 8, 1, 3, 16, 10, 20 };
    int size_unsortedArray = sizeof(unsortedArray) / sizeof(unsortedArray[0]);

    int l = 0;
    int r = size_unsortedArray - 1;

    mergeSorting(unsortedArray, l, r);
    displayArray(unsortedArray, size_unsortedArray);

    return(0);
}
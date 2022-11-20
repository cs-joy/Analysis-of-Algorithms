#include<iostream>
#include "msNamespace.hpp"

using namespace subMerge;

void mergeSorting(int array[], int lowerBound, int upperBound)
{
    if (lowerBound < upperBound)
    {
        int midBound = lowerBound + (upperBound - lowerBound) / 2;

        mergeSorting(array, lowerBound, midBound);
        mergeSorting(array, midBound + 1, upperBound);

        // merge the sorted arrays
        merge(array, lowerBound, midBound, upperBound);
    }
}

void displayArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
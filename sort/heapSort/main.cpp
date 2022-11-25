#include<iostream>
#include "heapify.hpp"
#include "disNamespace.hpp"

using namespace std;
using namespace buildHeap;

int main()
{
    int myArr[] = { 1, 12, 9, 5, 6, 10 };
    int size_of_myArr = sizeof(myArr) / sizeof(myArr[0]);
    cout << "Unsorted array is: ";
    println::display(myArr, size_of_myArr);

    heapSort(myArr, size_of_myArr);
    cout << "Sorted array is: ";
    println::display(myArr, size_of_myArr);

    return(0);
}

// Heapsort can be thought of as an improved selection sort

/**
 * prerequisite:
 * binary tree
 * heap data structure
*/

/**
 * overview::
 * *
 *iParent(i)     = floor((i-1) / 2) where floor functions map a real number to the largest leading integer.
  iLeftChild(i)  = 2*i + 1
  iRightChild(i) = 2*i + 2
*/

/**
 * variations::
    * Floyd's heap construction
    * Bottom-up heapsort
*/

// ref: https://en.wikipedia.org/wiki/Heapsort
// ref: https://www.programiz.com/dsa/heap-sort
// ref: https://www.geeksforgeeks.org/heap-sort/
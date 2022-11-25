#include<iostream>

using namespace std;

int main()
{
    int myArr[] = { 1, 12, 9, 5, 6, 10 };
    int size_of_myArr = sizeof(myArr) / sizeof(myArr[0]);
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
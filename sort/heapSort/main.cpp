
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
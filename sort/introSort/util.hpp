#include "insertionSort.hpp"

namespace IntroSortUtil
{
    // a utility function to perform intro sort
    void utility(int arr[], int* begin, int* end, int depthLimit)
    {
        // count the number of elements
        int size = end - begin;

        // if the partition size less than 16 then do insertion sort
        if(size < 16)
        {
            insertion(arr, begin, end);
            return;
        }

        // if the depth is zero use heapsort
        if(size == 0)
        {
            //
        }
    }
}
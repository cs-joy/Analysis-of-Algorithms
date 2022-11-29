#include<algorithm>
#include "insertionSort.hpp"
#include "medianSpace.hpp"
#include "swapSpace.hpp"
#include "partitionPoint.hpp"

using namespace std;
using namespace findMedian;
using namespace swapSpace;

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
        if(depthLimit == 0)
        {
            make_heap(begin, end+1); // function comes from <algorithm>
            sort_heap(begin, end+1); // function comes from <algorithm>
            
            return;
        }

        // else use a median of three concept to find a good pivot
        int* pivot = MedianOfThree(begin, begin+size/2, end);

        // swap the values pointed by the pointers
        swaping(pivot, end);

        // perform quick sort
        int* partitionPoint = partition(arr, begin-arr, end-arr);
        utility(arr, begin, partitionPoint-1, depthLimit-1);
        utility(arr, partitionPoint+1, end, depthLimit-1);

        return;
    }
}
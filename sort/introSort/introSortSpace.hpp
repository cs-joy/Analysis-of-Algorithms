#include<cmath>
#include "util.hpp"

using namespace IntroSortUtil;

namespace implementationIntroSort
{
    void IntroSort(int arr[], int* begin, int* end)
    {
        int depthLimit = 2 * log(end-begin);

        // perform a recursive introsort
        utility(arr, begin, end, depthLimit);

        return;
    }
}
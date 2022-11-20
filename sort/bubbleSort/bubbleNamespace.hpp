
namespace bsSecondImplementation
{
    void bsOptimised(int arr[], int n)
    {
        for(int s=0; s<n-1; s++)
        {
            bool isSwap = false;

            for(int j=0; j<n-s-1; j++)
            {
                if(arr[j] > arr[j+1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;

                    isSwap = true;
                }
            }

            if(isSwap == false)
            {
                break;
            }
        }

        //displaying
        for(int d=0; d<n; d++)
        {
            std::cout << arr[d] << " ";
        }
        std::cout << std::endl;
    }
}
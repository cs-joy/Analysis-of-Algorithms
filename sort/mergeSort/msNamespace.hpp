namespace subMerge
{
    void merge(int arr[], int left, int mid, int right)
    {
        int s1 = mid - left + 1;
        int s2 = right - mid;

        // create left sub array and right sub array
        int leftSub[s1];
        int rightSub[s2];
        
        // assign value in left side array from original array
        for(int i=0; i<s1; i++)
        {
            leftSub[i] = arr[left+i];
        }

        // assign value in left side array from original array
        for(int j=0; j<s2; j++)
        {
            rightSub[j] = arr[mid+1+j];
        }

        // maintain current index of sub arrays and original
        int i = 0, j = 0, k = left;
        
        // Until we reach either end of either leftSub or rightSub, pick larger among
        // elements leftSub and rightSub and place them in the correct position at arr[left..right]
        while(i < s1 && i < s2)
        {
            if(leftSub[i] <= rightSub[j])
            {
                arr[k] = leftSub[i];
                i++;
            }
            else
            {
                arr[k] = rightSub[j];
                j++;
            }
            k++;
        }

        // when we run out of elements in either leftSub or rightSub
        // pick up the remaining elements and put in arr[left...right]
        while(i < s1)
        {
            arr[k] = leftSub[i];
            i++;
            k++;
        }

        while(j < s2)
        {
            arr[k] = rightSub[j];
            j++;
            k++;
        }
    }
}
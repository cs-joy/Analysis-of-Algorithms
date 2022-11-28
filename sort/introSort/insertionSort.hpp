
void insertion(int arr[], int* begin, int* end)
{
    // get the left and right index of subarray to be sorted
    int left = begin - arr;
    int right = end - arr;

    for(int i = left + 1; i <= right; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements of array[0...i-1], that are greater than key, to one position ahead of their current position
        while(j >= left && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    return;
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;

    return;
}

// function to partition the array and return partition point
int* partition(int arr[], int low, int high)
{
    // pivot
    int pivot = arr[high];
    int i = low - 1; // index of smaller element

    for(int j = low; j <= high - 1; j++)
    {
        // if the current element smaller than or equal to pivot
        if(arr[j] <= pivot)
        {
            // increment index of smaller element
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);

    return(arr+i+1);
}
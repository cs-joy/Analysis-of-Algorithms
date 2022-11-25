void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

namespace Heapifying
{
    void heapify(int arr[], int n, int i)
    {
        // Find the largest among root, left child and right child
        int largest = i;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        if (leftChild < n && arr[leftChild] > arr[largest])
        {
            largest = leftChild;
        }

        if (rightChild < n && arr[rightChild] > arr[largest])
        {
            largest = rightChild;
        }

        // Swap and continue heapifying if the root is not largest
        if (largest != i)
        {
            swap(&arr[i], &arr[largest]);
            heapify(arr, n, largest);
        }
    }
}

namespace buildHeap
{
    // main function to do heap sort
    void heapSort(int arr[], int n)
    {
        // build max heap
        for(int i = n/2-1; i>=0; i--)
        {
            Heapifying::heapify(arr, n, i);
        }

        // heap sort
        for(int i = n-1; i>=0; i--)
        {
            swap(&arr[0], &arr[i]);
            //Heapify root element to get higher element at root again
            Heapifying::heapify(arr, i, 0);
        }
    }
}
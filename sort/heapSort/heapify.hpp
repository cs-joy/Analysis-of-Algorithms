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

            // Swap and continue heapifying if the root is not largest
            if (largest != i)
            {
                swap(&arr[i], &arr[largest]);
                heapify(arr, n, largest);
            }
        }
    }
}
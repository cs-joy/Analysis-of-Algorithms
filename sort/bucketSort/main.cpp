/**
 bucketSort()
  create N buckets each of which can hold a range of values
  for all the buckets
    initialize each bucket with 0 values
  for all the buckets
    put elements into buckets matching the range
  for all the buckets 
    sort elements in each bucket
  gather elements from each bucket
end bucketSort
*/


#include<iostream>
#include<iomanip> // for setw()

using namespace std;

#define NARRAY 7 // main array_size
#define NBUCKET 6 // array_size-1 *number of buckets
#define INTERVAL 10 // each bucket capacity

struct Node
{
    int data;
    struct Node *next;
};

void bucketSort(int arr[]);
struct Node *insertionSort(struct Node *list);
void displayArray(int arr[]);
void printBuckets(struct Node *list);
int getBucketIndex(int value);



void bucketSort(int arr[])
{
    int i, j;
    struct Node **buckets;

    // create buckets and allocate memory size
    buckets = (struct Node **)malloc(sizeof(struct Node *) * NBUCKET);

    // initialize empty buckets
    for(i=0; i<NBUCKET; i++)
    {
        buckets[i] = NULL;
    }

    // fill the buckets with respective elements
    for(i=0; i<NARRAY; i++)
    {
        struct Node *current;
        int pos = getBucketIndex(arr[i]);
        current = (struct Node * )malloc(sizeof(struct Node));
        current->data = arr[i];
        current->next = buckets[pos];
        buckets[pos] = current;
    }
    
    // print the buckets along with their elements
    for(i=0; i<NBUCKET; i++)
    {
        cout << "Bucket[" << i <<"] : ";
        printBuckets(buckets[i]);
        cout << endl;
    }
    

    // sort the elements of each bucket
    for(i=0; i<NBUCKET; i++)
    {
        buckets[i] = insertionSort(buckets[i]);
    }
    
    cout << "--------------" << endl;
    cout << "Buckets after sorted" << endl;
    for(i=0; i<NBUCKET; i++)
    {
        cout << "Bucket[" << i << "] : ";
        printBuckets(buckets[i]);
        cout << endl;
    } 
    

    // put sorted elements on the main array
    for(j=0, i=0; i<NBUCKET; i++)
    {
        struct Node *node;
        node = buckets[i];
        while(node)
        {
            arr[j++] = node->data;
            node = node->next;
        }
    }

    for(i=0; i<NBUCKET; i++)
    {
        struct Node *node;
        node = buckets[i];
        while(node)
        {
            struct Node *tmp;
            tmp = node;
            node = node->next;
            free(tmp); // bucket erased
        }
    }
    free(buckets); // buckets erased
    
    return;
}


// function to sort the elements of each bucket
struct Node *insertionSort(struct Node *list)
{
    struct Node *k, *nodeList;
    if(list == 0 || list->next == 0)
    {
        return list;
    }

    nodeList = list;
    k = list->next;
    nodeList->next = 0;
    while(k != 0)
    {
        struct Node *ptr;
        if(nodeList->data > k->data)
        {
            struct Node *tmp;

            tmp = k;
            k = k->next; // semactic error was found here
            tmp->next = nodeList;
            nodeList = tmp;
            continue;
        }

        for(ptr = nodeList; ptr->next != 0; ptr=ptr->next)
        {
            if(ptr->next->data > k->data)
            {
                break;
            }
            /*
              semantic error was found here
            */
        }

        /*
        semantic error was found here
        */
        if (ptr->next != 0)
        {
            struct Node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = ptr->next;
            ptr->next = tmp;
            continue;
        }
        else
        {
            ptr->next = k;
            k = k->next;
            ptr->next->next = 0;
            continue;
        }
    }

    return nodeList;
}


//
int getBucketIndex(int value)
{
    return value/INTERVAL;
}


// display array
void displayArray(int arr[])
{
    for(int i=0; i<NARRAY; i++)
    {
        cout << setw(3) << arr[i];
    }
    cout << endl;
}


/// display buckets
void printBuckets(struct Node *list)
{
    struct Node *cur = list;
    while(cur)
    {
        cout << setw(3) << cur->data;
        cur = cur->next;
    }
}


int main() 
{
    int myArray[NARRAY] = {42, 32, 23, 52, 25, 47, 51};
    cout << "Initial Array:" << endl;
    displayArray(myArray);
    cout << "--------------------" << endl;

    bucketSort(myArray);
    // bucket sort
    cout << "-------------------" << endl;
    cout << "Sorted Array:" << endl;
    displayArray(myArray);

    return(0);
}

/*
expected output::

Initial Array:
 42 32 23 52 25 47 51
--------------------
Bucket[0] :
Bucket[1] :
Bucket[2] :  25 23
Bucket[3] :  32
Bucket[4] :  47 42
Bucket[5] :  51 52
--------------
Buckets after sorted
Bucket[0] :
Bucket[1] :
Bucket[2] :  23 25
Bucket[3] :  32
Bucket[4] :  42 47
Bucket[5] :  51 52
-------------------
Sorted Array:
23 25 32 42 47 51 52

*/


// ref:: https://www.geeksforgeeks.org/bucket-sort-2/
// ref:: https://www.programiz.com/dsa/bucket-sort
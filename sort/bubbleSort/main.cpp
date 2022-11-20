#include<iostream>
#include"bubbleNamespace.hpp"

using namespace std;
using namespace bsSecondImplementation;

void _bubbleSort(int a[], int n);

void display(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

class bsFirstImplementation
{
    private:
        int temp=0;

        void bubble_sort(int j[], int n)
        {
            for(int i=0; i<n-1; i++)
            {
                for(int s=0; s<n-i-1; s++)
                {
                    if(j[s] > j[s+1])
                    {
                        temp = j[s];
                        j[s] = j[s+1];
                        j[s+1] = temp;
                    }
                }
            }
            display(j, n);
        }

    public:

        bsFirstImplementation(int ar[], int n)
        {
            bubble_sort(ar, n);
        }
};

int main()
{
    int unsortedArray[] = { 15, 16, 6 ,8, 5 };
    int size = sizeof(unsortedArray)/sizeof(unsortedArray[0]);

    /*
      * original
    */
    //_bubbleSort(unsortedArray, size);

    /*
      * first implementation
    */
    // bsFirstImplementation* bsObj = new bsFirstImplementation(unsortedArray, size);

    /*
      * optimised
    */
    bsOptimised(unsortedArray, size);


    return(0);
}

void _bubbleSort(int arr[], int n)
{
    int temp=0;
    //pass
    for(int i=0; i<n-1; i++)
    {
        //iteration
        for(int j=0; j<n-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    display(arr, n);
}
#include<iostream>

using namespace std;

// prototype
void countingSort(int array[], int n, int k); // note:: in prototype `;` should be have

// displaying array
void display(int array[], int n)
{
  for(int i=0; i<n; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;
}

int main()
{
  int unsortedArray[] = { 2, 1, 4, 7, 1, 4, 7, 0, 4, 2, 7, 1, 8, 4, 3, 9, 5 };
  int n = sizeof(unsortedArray)/sizeof(unsortedArray[0]);
  
  int k = 0;
  
  // find k or say maximum value of `unsortedArray`
  for(int i=0; i<n; i++)
  {
    if(unsortedArray[i] > unsortedArray[0])
    {
      unsortedArray[0] = unsortedArray[i];
      
      k = unsortedArray[0];
    }
  }
  
  countingSort(unsortedArray, n, k);
  
    return(0);
}

// function for count_sort
void countingSort(int array[], int n, int k)
{
  int sortedArray[n];
  int count[k];
  
  // initialzing with zero
  for(int i=0; i<=k; i++)
  {
    count[i] = 0;
  }
  
  // counting element of the given unsorted array
  for(int i=0; i<n; i++)
  {
    count[array[i]]++;
  }
  
  // cumulative count
  for(int i=1; i<=k; i++)
  {
    count[i] = count[i] + count[i-1];
  }
  
  // sorted element
  for(int i=n-1; i>=0; i--)
  {
    sortedArray[--count[array[i]]] = array[i];
  }
  
  // copy sorted array element to the original array
  for(int i=0; i<n; i++)
  {
    array[i] = sortedArray[i];
  }
  
  // displaying the original array
  display(array, n);
}
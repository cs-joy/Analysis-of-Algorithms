#include<iostream>

namespace println
{
    void display(int arr[], int n)
    {
        for(int i = 0; i<n; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
}
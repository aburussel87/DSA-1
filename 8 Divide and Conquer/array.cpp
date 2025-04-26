#include <iostream>
#include "mySort.h"
using namespace std;

int main()
{
    int arr[] = {1, 2, 5, 5, 4, 3, 1,7};
    quick_sort(arr, 8);
    for (int v : arr)
    {
        cout << v << " ";
    }
    return 0;
}
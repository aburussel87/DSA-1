#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

// Counting Sort used as a subroutine in Radix Sort
void countingSort(vector<int> &arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    // Count occurrences of digits
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Update count array to store actual positions
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy back to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort
void radixSort(vector<int> &arr) {
    int maxVal = *max_element(arr.begin(),arr.end());

    // Apply counting sort for each digit
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

// Driver Code
int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}

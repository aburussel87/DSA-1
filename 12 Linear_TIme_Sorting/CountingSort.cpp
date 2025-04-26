#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Counting Sort
void countingSort(vector<int> &arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    vector<int> count(range, 0), output(arr.size());

    // Store frequency of elements
    for (int num : arr)
        count[num - minVal]++;

    // Update count array to store actual positions
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    // Build output array
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    // Copy back to original array
    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

// Driver Code
int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    countingSort(arr);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[i], arr[min_idx]);
    }
}

int main() {
    vector<int> a = {5, 2, 9, 1, 5, 6};
    
    selectionSort(a);

    for (int x : a) cout << x << " ";
    cout << endl;
    return 0;
}

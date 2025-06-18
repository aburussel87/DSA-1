#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int main() {
    vector<int> a = {5, 2, 9, 1, 5, 6};

    bubbleSort(a);

    for (int x : a) cout << x << " ";
    cout<<endl;

    return 0;
}

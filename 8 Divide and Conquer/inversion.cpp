#include <iostream>
#include <vector>
using namespace std;
int merge(vector<int> &arr, vector<int> &temp, int left, int mid, int right);
int mergeAndCount(vector<int> &arr, vector<int> &temp, int left, int right)
{
    if (left == right)
    {
        return 0;
    }

    int mid = (left + right) / 2;
    int c = 0;

    c += mergeAndCount(arr, temp, left, mid);
    c += mergeAndCount(arr, temp, mid + 1, right);

    c += merge(arr, temp, left, mid, right);

    return c;
}
int merge(vector<int> &arr, vector<int> &temp, int left, int mid, int right)
{
    if (left == right)
    {
        return 0;
    }
    int k = left;
    int crosscount = 0;
    int i = left;
    int j = mid + 1;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            crosscount += mid - i + 1;
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }
    for (int i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
    return crosscount;
}
int count(vector<int> &arr)
{
    vector<int> temp(arr);
    return mergeAndCount(arr, temp, 0, arr.size() - 1);
}
int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    cout << count(arr);
    return 0;
}
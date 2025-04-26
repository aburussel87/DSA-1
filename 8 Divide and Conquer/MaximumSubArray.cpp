#include <iostream>
#include <vector>
using namespace std;

int getsum(int *arr, int a, int b)
{
    int s = 0;
    for (int i = a; i <= b; i++)
    {
        s += *(arr + i);
    }
    return s;
}

int getmax(int a, int b, int c)
{
    return a > b ? (c > a ? c : a) : (c > b ? c : b);
}

vector<int> maxsum(int arr[], int low, int high)
{
    if (low == high)
    {
        return {low, high};
    }

    int mid = (low + high) / 2;
    vector<int> leftmaxrange = maxsum(arr, low, mid);
    vector<int> rightmaxrange = maxsum(arr, mid + 1, high);

    int cleft = -2147483648;
    int cright = -2147483648;
    int sum = 0;
    int cleft_index = mid;
    int cright_index = mid + 1;

    for (int i = mid; i >= low; i--)
    {
        sum += arr[i];
        if (sum > cleft)
        {
            cleft = sum;
            cleft_index = i;
        }
    }

    sum = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        if (sum > cright)
        {
            cright = sum;
            cright_index = i;
        }
    }

    int sleft = getsum(arr, leftmaxrange[0], leftmaxrange[1]);
    int sright = getsum(arr, rightmaxrange[0], rightmaxrange[1]);
    int scross = getsum(arr, cleft_index, cright_index);
    int max = getmax(sleft, sright, scross);

    if (max == sleft && max == sright && max == scross)
    {
        int lenLeft = leftmaxrange[1] - leftmaxrange[0] + 1;
        int lenRight = rightmaxrange[1] - rightmaxrange[0] + 1;
        int lenCross = cright_index - cleft_index + 1;
        if (lenLeft <= lenRight && lenLeft <= lenCross)
        {
            return leftmaxrange;
        }
        else if (lenRight <= lenLeft && lenRight <= lenCross)
        {
            return rightmaxrange;
        }
        else
        {
            return {cleft_index, cright_index};
        }
    }

    if (max == sleft && max == sright)
    {
        int lenLeft = leftmaxrange[1] - leftmaxrange[0] + 1;
        int lenRight = rightmaxrange[1] - rightmaxrange[0] + 1;
        return lenLeft <= lenRight ? leftmaxrange : rightmaxrange;
    }

    if (max == sleft && max == scross)
    {
        int lenLeft = leftmaxrange[1] - leftmaxrange[0] + 1;
        int lenCross = cright_index - cleft_index + 1;
        return lenLeft <= lenCross ? leftmaxrange : vector<int>{cleft_index, cright_index};
    }

    if (max == sright && max == scross)
    {
        int lenRight = rightmaxrange[1] - rightmaxrange[0] + 1;
        int lenCross = cright_index - cleft_index + 1;
        return lenRight <= lenCross ? rightmaxrange : vector<int>{cleft_index, cright_index};
    }

    if (max == sleft)
    {
        return leftmaxrange;
    }
    else if (max == sright)
    {
        return rightmaxrange;
    }
    else
    {
        return {cleft_index, cright_index};
    }
}

int main()
{
    int arr[8] = {6, 3, -10, 3, -2, 5, -1, 4};
    vector<int> max_sub = maxsum(arr, 0, 7);
    int sum = 0;
    cout << "[";
    for (int i = max_sub[0]; i <= max_sub[1]; i++)
    {
        sum += arr[i];
        cout << arr[i];
        if (i != max_sub[1])
        {
            cout << ",";
        }
    }
    cout << "]" << " with sum " << sum;
    return 0;
}

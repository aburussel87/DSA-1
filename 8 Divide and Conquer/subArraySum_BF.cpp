#include <iostream>
using namespace std;
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int max = -2147483648;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i <= j)
            {
                int sum = 0;
                for (int k = i; k <= j; k++)
                {
                    cout << arr[k] << " ";
                    sum += arr[k];
                }
                cout << "sum is: " << sum << endl;
            }
        }
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int cutRod(vector<int> &nums, int n,vector<int> &cut, unordered_map<int, int> &hash = *(new unordered_map<int, int>()))
{
    auto it = hash.find(n);
    if (it != hash.end())
    {
        return hash[n];
    }
    if (n == 0)
    {
        return 0;
    }
    int q = INT16_MIN;
    int maxindex = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        int x = nums[i] + cutRod(nums, n - i - 1, cut, hash);
        if(x>q){
            q = x;
            maxindex = i;
        }
    }
    cut.push_back(maxindex+1);
    hash[n] = q;
    return q;
}

int main()
{
    vector<int> nums = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    vector<int> cut;
    cout << cutRod(nums, 10, cut)<<endl;
    for(int v: cut){
        cout<< v <<" ";
    }
    return 0;
}
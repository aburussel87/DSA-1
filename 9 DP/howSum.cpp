#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> howSum(int target, vector<int> &nums, unordered_map<int, vector<int>> &hash = *(new unordered_map<int, vector<int>>()))
{
    auto it = hash.find(target);
    if (it != hash.end())
        return it->second;
    if (target == 0)
    {
        return {0};
    }
    if (target < 0)
        return {};

    for (int v : nums)
    {
        int remainder = target - v;
        vector<int> final(howSum(remainder, nums, hash));
        if (final.size() != 0)
        {
            final.push_back(v);
            hash[target] = final;
            return final;
        }
    }
    hash[target] ={};
    return {};
}
int main()
{
    vector<int> nums = {7,15};
    vector<int> combin = howSum(44, nums);
    if(combin.size() == 0){
        cout<<"{ }";
        return 0;
    }
    for (int n : combin)
    {
        if (n == 0)
            continue;
        cout << n << " ";
    }
    return 0;
}
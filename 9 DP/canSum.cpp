#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool canSum(int target, vector<int> &nums, unordered_map<int, bool> &hash)
{
    if (hash.find(target) != hash.end())
    {
        return hash[target];
    }
    if (target < 0)
        return false;
    if (target == 0)
        return true;

    for (int v : nums)
    {
        int remainder = target - v;
        if (canSum(remainder, nums, hash))
        {
            hash[target] = true;
            return true;
        }
    }

    hash[target] = false;
    return false;
}

int main()
{
    vector<int> nums = {7,14};
    unordered_map<int, bool> hash;  // Create the memoization map
    cout << (canSum(3211, nums, hash) ? "true" : "false") << endl;
    return 0;
}

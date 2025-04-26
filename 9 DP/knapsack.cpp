#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int ks(vector<int> &weights, vector<int> &price, int weight, int ob, unordered_map<string, int> &memo = *(new unordered_map<string,int> ()))
{
    if (ob < 0)
    {
        return 0;
    }

    string key = to_string(ob) + "_" + to_string(weight);
    if (memo.find(key) != memo.end())
    {
        return memo[key];
    }

    int notTake = ks(weights, price, weight, ob - 1, memo);
    int take = INT32_MIN;

    if (weight >= weights[ob])
    {
        take = price[ob] + ks(weights, price, weight - weights[ob], ob, memo);
    }

    memo[key] = max(notTake, take);
    return memo[key];
}

int main()
{
    vector<int> weights = {2, 4, 6};
    vector<int> price = {5, 11, 13};
    unordered_map<string, int> memo;
    cout << ks(weights, price, 10000, 3, memo);
    return 0;
}

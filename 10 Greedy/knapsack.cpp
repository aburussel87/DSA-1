#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct
{
    double val;
    double weight;
} item;

bool compare(item a, item b)
{
    return (a.val / a.weight) > (b.val / b.weight);
}
double ks(vector<item> items, int weight)
{
    double total = 0;
    int i = 0;
    while (weight > 0 && i < items.size())
    {
        if (weight >= items[i].weight)
        {
            total += items[i].val;
            weight -= items[i].weight;
        }
        else
        {
            total += (items[i].val / items[i].weight) * weight;
            weight = 0;
        }
        i++;
    }
    return total;
}
int main()
{
    vector<item> items = {{100, 20}, {60, 10}, {100, 50}, {200, 50}};
    sort(items.begin(), items.end(), compare);
    cout << ks(items, 90);
    return 0;
}
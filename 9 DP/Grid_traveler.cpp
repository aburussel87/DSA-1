#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

long long int grid_traveler(int m, int n, unordered_map<string, long long int> &hash = *(new unordered_map<string, long long int>())) {
    string s = to_string(m) + "," + to_string(n);
    auto it = hash.find(s);
    if (it != hash.end()) {
        return it->second;
    }
    if (m == 1 && n == 1) {
        return 1;
    }
    if (m == 0 || n == 0) {
        return 0;
    }
    hash[s] = grid_traveler(m - 1, n, hash) + grid_traveler(m, n - 1, hash);
    return hash[s];
}

int main() {
    cout << grid_traveler(3, 2) << endl; 
    cout << grid_traveler(18,18) <<endl;
    cout << grid_traveler(20,20) <<endl;
    return 0;
}

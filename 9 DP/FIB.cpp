#include <iostream>
#include <unordered_map>
using namespace std;

long long int fib(long long int n, unordered_map<long long int, long long int>& hash = *(new unordered_map<long long int, long long int>())) {
    auto it = hash.find(n);
    if (it != hash.end()) {
        return it->second;
    }
    if (n <= 2) {
        return 1;
    }
    
    long long int r = fib(n - 1, hash) + fib(n - 2, hash);
    hash[n] = r;
    return r;
}

 int main() {
    cout << fib(5) << " "; 
    cout << fib(10) << " ";
    cout << fib(40) << " ";  
    cout << fib(150) << endl; 
    return 0;
}

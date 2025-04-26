#include <stack>
#include <string>
#include <iostream>
using namespace std;

class BrowserHistory {
private:
    stack<string> s1; // Stack for the back history
    stack<string> s2; // Stack for the forward history
public:
    BrowserHistory(string homepage) {
        s1.push(homepage); // Initialize with the homepage
    }
    
    void visit(string url) {
        s1.push(url); // Add the new URL to the back stack
        // Clear the forward stack since we can't go forward from a new page
        while (!s2.empty()) {
            s2.pop();
        }
    }
    
    string back(int steps) {
        while (steps > 0 && s1.size() > 1) { // Check if we can go back
            s2.push(s1.top()); // Move the current page to the forward stack
            s1.pop(); // Go back
            steps--;
        }
        return s1.top(); // Return the current page (the top of s1)
    }
    
    string forward(int steps) {
        while (steps > 0 && !s2.empty()) { // Check if we can go forward
            s1.push(s2.top()); // Move the page from forward stack to back stack
            s2.pop(); // Go forward
            steps--;
        }
        return s1.top(); // Return the current page (the top of s1)
    }
};

int main() {
    BrowserHistory* obj = new BrowserHistory("google.com");
    obj->visit("facebook.com");
    obj->visit("leetcode.com");
    
    cout << obj->back(5) << endl; 
    cout << obj->forward(1) << endl; 
    cout << obj->back(2) << endl; 
    cout << obj->forward(3) << endl; 

    delete obj; // Clean up
    return 0;
}

#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;

#define MAX 100

int main()
{
    // Redirect input and output
    if (!freopen("bracket.txt", "r", stdin)) {
        cerr << "Error opening input file\n";
        return 1;
    }
    if (!freopen("bracket_out.txt", "w", stdout)) {
        cerr << "Error opening output file\n";
        return 1;
    }

    string s;
    int pos;
    
    getline(cin, s); // Read the full bracket string
    cin >> pos;      // Read the position

    if (pos < 0 || pos >= s.length() || s[pos] != '[') {
        cout << "Closing bracket not found\n";
        return 0;
    }

    stack<char> st;
    int fpos = -1;

    for (int i = pos + 1; i < s.length(); i++) {
        char symbol = s[i];
        if (symbol == '[') {
            st.push(symbol);
        } else if (symbol == ']') {
            if (st.empty()) {
                fpos = i;
                break;
            } else {
                st.pop();
            }
        }
    }

    cout << fpos << endl;

    return 0;
}

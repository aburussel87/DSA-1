#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main()
{
    FILE *fin = freopen("postfix_input.txt", "r", stdin);

    int n;
    cin >> n;
    cin.ignore(); // Ignore the newline after reading `n`

    string s[n];
    for (int i = 0; i < n; i++)
    {
        getline(cin, s[i]);
    }

    cout << "Number of tokens: " << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;

    int result;
    stack<int> carrier;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == " ")
            continue;

        if (s[i] == "+" || s[i] == "-" || s[i] == "*" || s[i] == "/")
        {
            // Extract the operator
            char symbol = s[i][0];
            int b = carrier.top(); // Second operand
            carrier.pop();
            int a = carrier.top(); // First operand
            carrier.pop();

            switch (symbol)
            {
            case '*':
                result = a * b;
                break;
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '/':
                result = a / b;
                break;
            }
            carrier.push(result); // Push the result back onto the stack
        }
        else
        {
            // Handle empty strings or invalid inputs
            if (isdigit(s[i][0]))
            {
                // It's a number, convert it to int and push onto the stack
                int num = stoi(s[i]);
                carrier.push(num);
            }
            else
            {
                cerr << "Invalid input or empty string found: " << s[i] << endl;
            }
        }
    }
    cout << "Final result: " << carrier.top() << endl;
    fclose(fin);
    return 0;
}

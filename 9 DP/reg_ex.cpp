#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

bool isMatching(const string &t, const string &p)
{
    int n = t.length();
    int m = p.length();
    if (t.size() == 0)
    {
        vector<bool> dp(m + 1, false);
        dp[0] = true;
        for (int i = 2; i <= m; i++)
        {
            if (p[i - 1] == '*')
            {
                dp[i] = dp[i - 2];
            }
            else if (p[i - 1] == '+')
            {
                dp[i] = false;
            }
        }
        return dp[0];
    }
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    dp[0][0] = true;
    for (int i = 2; i <= m; i++)
    {
        if (p[i - 1] == '*')
        {
            dp[i][0] = dp[i - 2][0];
        }
        else if (p[i - 1] == '+')
        {
            dp[i][0] = false;
        }
    }

    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (j == 0 && i != 0)
            {
                dp[j][i] = true;
            }
            char curr_p = p[j - 1];
            char curr_t = t[i - 1];

            if (curr_p == t[i - 1] || curr_p == '.')
            {
                dp[j][i] = dp[j - 1][i - 1];
            }
            else if (curr_p == '*')
            {
                dp[j][i] = dp[j - 2][i];
                if (curr_t == p[j - 2] || p[j - 2] == '.')
                {
                    dp[j][i] = dp[j][i] || dp[j][i - 1];
                }
            }
            else if (curr_p == '+')
            {
                if (t[i - 1] == p[j - 2] || p[j - 2] == '.')
                {
                    dp[j][i] = dp[j - 1][i] || dp[j][i - 1];//changed this line from--> dp[j][i] = dp[j-1][i] || dp[j][i-1];
                }
            }
        }
    }
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (dp[i][j] == true)
            {
                cout << " T ";
            }
            else
                cout << " F ";
        }
        cout << endl;
    }

    return dp[m][n];
}

int main()
{
    freopen("input.txt", "r", stdin);
    int test;
    cin >> test;
    cin.ignore();

    for (int i = 0; i < test; ++i)
    {
        cout << (i + 1) << " :";
        string s;
        getline(cin, s);
        string t, p;

        if (s.empty())
        {
            t = "";
            p = "";
        }
        else if (s[0] != ' ')
        {
            istringstream iss(s);
            iss >> t >> p;
        }
        else
        {
            p = s.substr(1);
            t = "";
        }

        cout << "Text->" << t << " pattern->" << p << " :\n";
        if (isMatching(t, p))
        {
            cout << "True\n";
        }
        else
        {
            cout << "False\n";
        }
    }

    return 0;
}

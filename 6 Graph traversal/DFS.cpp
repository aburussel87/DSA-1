#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> graph, vector<bool> &visited, int root)
{
    visited[root] = true;
    cout << root + 1 << " ";
    for (int i = 0; i < graph[root].size(); i++)
    {
        if (!visited[graph[root][i]])
        {
            dfs(graph, visited, graph[root][i]);
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<bool> visited(n, false);
    vector<vector<int>> list(n);
    vector<int> disconnected;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > n || b > n)
        {
            cout << "invalid input\n";
            exit(1);
        }
        list[a - 1].push_back(b - 1);
        list[b - 1].push_back(a - 1);
    }
    cout << "Adjacency list: \n";
    int i = 1;
    for (auto &row : list)
    {
        cout << i++ << " :";
        for (auto &val : row)
        {
            cout << val + 1 << " ";
        }
        cout << "\n";
    }

    cout << "connected components: \n";
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            disconnected.push_back(i + 1);
            dfs(list, visited, i);
            cout << "\n";
        }
    }
    if (disconnected.size() > 1)
    {
        cout << "Tunnels needed: " << disconnected.size() - 1 << "\n";
        for (int i = 0; i < disconnected.size() - 1; i++)
        {
            cout << disconnected[i] << " " << disconnected[i + 1] << "\n";
        }
    }
    return 0;
}
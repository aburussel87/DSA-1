#include <iostream>
#include <vector>
#include <queue>
using namespace std;



void bfs(vector<vector<int>> graph, vector<bool> &visited, vector<vector<int>> &cc, int root)
{
    visited[root] = true;
    vector<int> connected;
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int x = q.front();
        connected.push_back(x);
        q.pop();
        for (int i = 0; i < graph.size(); i++)
        {
            if (graph[x][i] == 1 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cc.push_back(connected);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("bfsoutput.txt","w",stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    vector<bool> visited(n, false);
    vector<vector<int>> connected_component;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > n || b > n)
        {
            cout<<"Invalid input\n";
            exit(1);
        }
        matrix[a - 1][b - 1] = 1;
        matrix[b - 1][a - 1] = 1;
    }
    cout<<"Adjacency Matrix: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bfs(matrix, visited, connected_component, i);
        }
    }

    cout << "Connected components:\n";
    for (auto &row : connected_component)
    {
        for (auto &val : row)
        {
            cout << val + 1 << " ";
        }
        cout << endl;
    }
    if (connected_component.size() > 1)
    {
        cout << "Tunnels needed: " << connected_component.size() - 1 << "\n";
        for (int i = 0; i < connected_component.size() - 1; i++)
        {
            auto p = connected_component[i].end() - 1;
            auto q = connected_component[i + 1].begin();
            cout << *p + 1 << " " << *q + 1 << "\n";
        }
    }
    else
    {
        cout << "No tunnels needed\n";
    }
    return 0;
}
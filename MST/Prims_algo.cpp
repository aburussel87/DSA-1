#include<iostream>
#include<queue>
using namespace std;

struct edge{
    int vertex,weight;
    edge(int a, int b){
        vertex = a;
        weight = b;
    }
};

void Prim(int V, vector<vector<edge>> &Graph){
    priority_queue<edge, vector<edge> ,greater<edge>> pq;
    
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<bool> visited(n, false);
    vector<vector<edge>> Graph(n);

    for(int i = 0; i<m; i++){
        int a,b,c;
        cin>> a >> b >> c;
        Graph[a-1].push_back(edge(b-1,c));
        Graph[b-1].push_back(edge(a-1,c));
    }
    cout << "Adjacency list: \n";
    for(int i = 0; i<n; i++){
        cout<<i+1<<": ";
        for(edge ed: Graph[i]){
            cout<<"( "<<ed.vertex + 1<<","<<ed.weight<<" )";
        }
        cout<<"\n";
    }
    return 0;
}
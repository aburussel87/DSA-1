#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
public:
    int weight, u, v;
    Edge(int weight, int u, int v){
        this->weight = weight;
        this->u = u;
        this->v = v;
    }
};

bool comparator(Edge& a, Edge& b) {
    return a.weight < b.weight;
}

int findParent(int node, vector<int>& parent) {
    if (parent[node] != node) {
        parent[node] = findParent(parent[node], parent);
    }
    return parent[node];
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);
    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

vector<Edge> MST(int n, const vector<Edge>& Graph) {
    vector<Edge> final;
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    int edgeTaken = 0;
    for (auto& edge : Graph) {
        if (edgeTaken == n - 1) break; 
        int rootU = findParent(edge.u, parent);
        int rootV = findParent(edge.v, parent);
        if (rootU != rootV) { 
            final.emplace_back(edge);
            unionSets(rootU, rootV, parent, rank);
            edgeTaken++;
        }
    }
    return final;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m; 
    cin >> n >> m;
    vector<Edge> Graph;
    for (int i = 0; i < m; i++) {
        int weight, u, v;
        cin >> weight >> u >> v;
        Graph.emplace_back(weight, u, v);
    }
    sort(Graph.begin(), Graph.end(), comparator);
    vector<Edge> mst = MST(n,Graph);
    int weight = 0;
    for(auto& edge: mst){
        weight += edge.weight;
    }
    cout<<weight;
    return 0;
}

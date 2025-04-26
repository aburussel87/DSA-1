#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<typename T>
struct vertex {
    T value;
    string color = "white";
    int d = 0;
    int f = 0;
    vertex* parent = nullptr;
};

template<typename T>
void DFS_VISIT(vector<vector<vertex<T>*>>& graph, vertex<T>& root, int& time) {
    time = time + 1;
    root.d = time;
    root.color = "gray";
    
    int n = 0;
    while (n < graph.size() && graph[n][0]->value != root.value) {
        n++;
    }
    
    for (int i = 1; i < graph[n].size(); i++) {
        if (graph[n][i]->color == "white") {
            graph[n][i]->parent = &root;
            DFS_VISIT(graph, *graph[n][i], time);
            //to unvisited descendent
            cout<<"Tree edge: "<<root.value<<"--->"<<graph[n][i]->value<<endl;
        }else{
            //to already visited vertex------:

            //to its visited ancestor
            //discovery time of dest. vertex must be smaller
            if(root.d>graph[n][i]->d){
                cout<<"Back edge: "<<root.value<<"--->"<<graph[n][i]->value<<endl;
            }else if(root.d<graph[n][i]->d){
            //to its visited descendent
            //discovery time of dest. vertex must be greater
                cout<<"Forward edge: "<<root.value<<"--->"<<graph[n][i]->value<<endl;
            }else if(root.d>graph[n][i]->d && root.f>graph[n][i]->f){
            //to a vertex having no descendent and ancestor relation, doesnt follow parentheses theorem
            //
                cout<<"Cross edge: "<<root.value<<"--->"<<graph[n][i]->value<<endl;
            }
        }
    }
    root.color = "black";
    time = time + 1;
    root.f = time;
}

template<typename T>
void DFS(vector<vector<vertex<T>*>>& graph) {
    int time = 0;
    
    for (int i = 0; i < graph.size(); i++) {
        if (graph[i][0]->color == "white") {
            DFS_VISIT(graph, *graph[i][0], time);
        }
    }
}

int main() {
    vertex<char> s; s.value = 's';
    vertex<char> t; t.value = 't';
    vertex<char> u; u.value = 'u';
    vertex<char> v; v.value = 'v';
    vertex<char> w; w.value = 'w';
    vertex<char> x; x.value = 'x';
    vertex<char> y; y.value = 'y';
    vertex<char> z; z.value = 'z';

    vector<vector<vertex<char>*>> graph(8);
    
    graph[0].push_back(&s);
    graph[1].push_back(&t);
    graph[2].push_back(&u);
    graph[3].push_back(&v);
    graph[4].push_back(&w);
    graph[5].push_back(&x);
    graph[6].push_back(&y);
    graph[7].push_back(&z);
    graph[0].push_back(&z);
    graph[0].push_back(&w);
    graph[1].push_back(&v);
    graph[1].push_back(&u);
    graph[2].push_back(&v);
    graph[2].push_back(&t);
    graph[3].push_back(&s);
    graph[3].push_back(&w);
    graph[4].push_back(&x);
    graph[5].push_back(&z);
    graph[6].push_back(&x);
    graph[7].push_back(&y);
    graph[7].push_back(&w);
    
    DFS(graph);

    for (int i = 0; i < graph.size(); i++) {
        cout << "Vertex " << graph[i][0]->value << ": d = " << graph[i][0]->d << ", f = " << graph[i][0]->f << endl;
    }

    return 0;
}

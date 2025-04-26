#include<iostream>
#include<vector>
using namespace std;

bool dfs(vector<vector<int>> graph, vector<int> &topsort, vector<bool> &visited,vector<bool> &restack, int root){
        visited[root] = true;
        restack[root] = true;
        for(int i = 0; i<graph[root].size(); i++){
            int neighboor = graph[root][i];
            if(!visited[neighboor]){
               if(dfs(graph,topsort,visited,restack,neighboor))
               return true;
            }else if(restack[neighboor]){
                return true;
            }
        }
        restack[root] = false;
        topsort.push_back(root);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses,false);
        vector<bool> restack(numCourses,false);
        vector<int> topsort;
        vector<vector<int>> graph(numCourses);
        for(int i = 0; i<prerequisites.size(); i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        bool iscycle = false;
        for(int i = 0; i<numCourses; i++){
            if(!visited[i]){
                iscycle = dfs(graph,topsort,visited,restack,i);
                if(iscycle){
                    return {};
                }
            }
        }
        return topsort;
    }
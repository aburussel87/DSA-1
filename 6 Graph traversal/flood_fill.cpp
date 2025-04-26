#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color || image.size() == 0) return image;
        queue<pair<int,int>> valid;
        valid.push(make_pair(sr,sc));
        int dx[]={0,0,-1,1};
        int dy[]={-1,1,0,0};
        long long int start= image[sr][sc];
        while(!valid.empty()){
            int r = valid.front().first;
            int c = valid.front().second;
            valid.pop();
            image[r][c] = color;
            for(int i = 0; i<4; i++){
                int nr = r+dx[i];
                int nc = c+dy[i];
                if(nr>=0 && nr<image.size() && nc>=0 && nc<image[0].size()){
                    if(image[nr][nc] == start){
                        image[nr][nc] = color;
                        valid.push(make_pair(nr,nc));
                    }
                }
            }
        }
        return image;
    }
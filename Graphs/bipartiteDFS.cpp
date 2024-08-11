#include<iostream>
#include<vector>
using namespace std;

class Solution{

    bool dfs(vector<int> &color, vector<vector<int>> & graph, int start, int col){
        color[start]=col; 

        for (auto it: graph[start]){
            if (color[it]==-1){
                if (!dfs(color, graph, it, !col)){
                    return false;
                }
            }else if (color[start]==color[it]){
                return false;
            }
        }
        return true;

    }
public:
    bool isBipartite(vector<vector<int>> & graph){
        int V=graph.size();
        vector<int> color(V,-1);
        for (int i=0; i<V; i++){
            if (color[i]==-1){
                if (!dfs(color, graph, i, 0)){
                    return false;
                }
            }
        }
        return true;
    }
};
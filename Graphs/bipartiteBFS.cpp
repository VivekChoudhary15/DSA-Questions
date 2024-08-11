// P.S.:- https://leetcode.com/problems/is-graph-bipartite/description/

#include<iostream>
#include<vector> 
#include<queue>
using namespace std;

class Solution{
    bool helperFn(int V, vector<vector<int>> adj, int color[], int start){
        queue<int> q;
        color[start]=0;
        q.push(start);

        while (!q.empty()){
            int node=q.front();
            q.pop();

            for (auto it: adj[node]){
                if (color[it]==-1){
                    q.push(it);
                    color[it]=!color[node];
                }
                else if (color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;

    }

public:
    bool isPartite(vector<vector<int>>& graph){
        int V=graph.size();
        int color[V];
        for (int i=0; i<V; i++){
            color[i]=-1;
        }

        for (int i=0; i<V; i++){
            if (color[i]==-1){
                if (!helperFn(V, graph, color, i)){
                    return false;
                }
            }
        }   
        return true;
    }
};
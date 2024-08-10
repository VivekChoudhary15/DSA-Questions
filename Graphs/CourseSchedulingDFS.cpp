// P.S.:- https://leetcode.com/problems/course-schedule/description/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    bool dfs(vector<int> adj[], bool visited[], int src, int parent){
        visited[src]=1;

        for (auto it: adj[src]){
            if (!visited[it]){
                visited[it]=1;
                if (dfs(adj, visited, it, src)){
                    return true;
                }
            }else if (it!=parent){
                return true;
            }
        }
        return false;
    }

public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        bool visited[n]={0};

        vector<int> adj[n]={{}};
        for (auto x:prerequisites){
            adj[x[0]].push_back(x[1]);
        }

        for (int i=0; i<n; i++){
            if (!visited[i]){
                if (dfs(adj, visited, i, -1)){
                    return false;
                }
            }
        }return true;
    }
};
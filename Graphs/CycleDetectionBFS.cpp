#include<iostream>
#include<queue>
#include <vector>
using namespace std;

class Solution{
    bool detect(int src, vector<vector<int>> &adj, bool visited[]){
        queue<pair<int,int>> q;

        q.push({src,-1});
        visited[src]=1;

        while (!q.empty()){
            int srcNode=q.front().first;
            int parent=q.front().second;
            q.pop();

            for (auto it: adj[srcNode]){
                if (!visited[it]){
                    visited[it]=1;
                    q.push({it,srcNode});
                }
                else if (it!=parent){
                    return true;
                }
            }
            return false;
        }
    }

public:

    bool detectCycle(int V, vector<vector<int>> adj){
        bool visited[V]={0};

        for(int i=0; i<V; i++){
            if (!visited[i]){
                if (detect(i, adj, visited)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solution;

    int V = 5;

    vector<vector<int>> adj(V);

    // Example graph:
    // 0 - 1
    // | \ |
    // 4 - 2
    // |
    // 3

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[0].push_back(4);
    adj[4].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[4].push_back(3);
    adj[3].push_back(4);

    bool hasCycle = solution.detectCycle(V, adj);

    if (hasCycle) {
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "Graph does not contain a cycle" << endl;
    }

    return 0;
}
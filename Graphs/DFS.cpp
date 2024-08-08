// P.S.:- https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    void DFS(int node, vector<int> adj[], vector<int> &result, vector<bool> &visited){
        result.push_back(node);
        visited[node] = 1;

        for (auto it: adj[node]){
            if (!visited[it]){
                DFS(it, adj, result, visited);
            }
        }
    }

public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);  // Fixes the issue of incorrect size initialization
        vector<int> result;

        int start = 0;  // Assuming the DFS starts from node 0

        DFS(start, adj, result, visited);
        return result;
    }
};

int main() {
    int V = 5;  // Number of vertice
    vector<int> adj[V];
  
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);

    Solution obj;
    vector<int> dfsResult = obj.dfsOfGraph(V, adj);

    cout << "DFS Traversal: ";
    for (int i = 0; i < dfsResult.size(); i++) {
        cout << dfsResult[i] << " ";
    }

    return 0;
}

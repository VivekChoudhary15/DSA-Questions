#include<iostream>
#include<vector>
#include <queue>
using namespace std;

class Solution {
  public:
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
      queue<int> q;
      vector<int> result;
      bool visited[V]={0};

      q.push(0);
      visited[0]=1;

      while(!q.empty()){
        int node=q.front();
        q.pop();
        result.push_back(node);

        for (auto it: adj[node]){
          if (!visited[it]){
            q.push(it);
            visited[it]=1;
          }
        }
      }    
      return result;
    }
};

int main() {
    int V = 5; // Number of vertices
    vector<int> adj[V]; // Adjacency list representation of the graph

    // Example graph
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(3);
    adj[3].push_back(4);

    Solution sol;
    vector<int> bfsResult = sol.bfsOfGraph(V, adj);

    cout << "BFS traversal of the graph:" << endl;
    for(int i = 0; i < bfsResult.size(); i++) {
        cout << bfsResult[i] << " ";
    }

    return 0;
}

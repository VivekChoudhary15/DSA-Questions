#include<iostream>
#include<vector>
using namespace std;

bool dfs(vector<int> adj[], bool visited[], int src, int parent){
    visited[src]=1;

    for (auto it: adj[src]){
        if (!visited[it]){
            if (dfs(adj, visited, it, src)) return true;
        }

        else if (it!=parent){
            return true;
        }
    }

    return false;
}

bool cycleDetection(vector<int> adj[], int N){
    bool visited[N]={0};

    for (int i=0; i<N; i++){
        if (!visited[i]){
            if (dfs(adj, visited, i, -1)){
                return true;
            }
        }
    }
    return false;
}

int main() {
    int V = 5;

    vector<int> adj[V];

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

    bool hasCycle = cycleDetection(adj, V);

    if (hasCycle) {
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "Graph does not contain a cycle" << endl;
    }

    return 0;
}
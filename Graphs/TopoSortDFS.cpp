#include <iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution{
    void findTopo(stack<int> &st, vector<bool> &visited, vector<int> adj[], int node){
        visited[node]=1;

        for(auto it: adj[node]){
            if (!visited[it]){
                findTopo(st, visited, adj, it);
            }
        }
        st.push(node);
    }

public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
        stack<int> st;
        vector<bool> visited;

        for (int i=0; i<V; i++){
            if (!visited[i]){
                findTopo(st, visited, adj, i);
            }
        }

        vector<int> result;
        for (int i=0; i<V; i++){
            result.push_back(st.top());
            st.pop();
        }
        return result;
	}
};

int main() {
    Solution obj;
    
    int V = 6;

    vector<int> adj[V];

    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> topo_order = obj.topoSort(V, adj);

    cout << "Topological Sort of the given graph:\n";
    for (int i : topo_order) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

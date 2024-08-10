#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
        queue<int> q;
        vector<int> indegree(V,0);
        vector<int> ans;

        for (int i=0; i<V; i++){
            for (auto it:adj[i]){
                indegree[it]++;
            }
        }

        for(int i=0; i<V; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for (auto it: adj[node]){
                indegree[it]--;
                if (indegree[it]==0){
                    q.push(it);
                }
            }
        }return ans;
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

#include<iostream>
#include<list>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

struct Node {
    int val;
    vector<Node*> neighbors;

    Node(){
        this->val=0;
        neighbors=vector<Node*>();
    }

    Node(int _val){
        this->val=_val;
        neighbors=vector<Node*>();
    }

    Node(int _val,vector<Node*>_neighbors){
        this->val=_val;
        this->neighbors=_neighbors;
    }
};


class Solution {
    public:
    Node* dfs(Node* cur,unordered_map<Node*,Node*>& mp)
    {
        vector<Node*> neighbour;
        Node* clone=new Node(cur->val);
        mp[cur]=clone;
            for(auto it:cur->neighbors)
            {
                if(mp.find(it)!=mp.end())   //already clone and stored in map
                {
                    neighbour.push_back(mp[it]);    //directly push back the clone node from map to neigh
                }
                else
                    neighbour.push_back(dfs(it,mp));
            }
            clone->neighbors=neighbour;
            return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(node==NULL) return NULL;
        if(node->neighbors.size()==0)   //if only one node present no neighbors
        {
            Node* clone= new Node(node->val);
            return clone; 
        }
        return dfs(node,mp);
    }
};
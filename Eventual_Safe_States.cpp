// This question is solve by DFS
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[],int check[]) {
        vis[node] = 1;       // Mark the current node as visited
        pathVis[node] = 1;   // Mark the current node as part of the current path
        check[node] = 0;

        //Traverse for adjacent nodes
        for (auto it : adj[node]) {
            if (!vis[it]) {
                // when the node is not visited
                if (dfsCheck(it, adj, vis, pathVis,check) == true) {
                    check[node] = 0;
                    return true;
                }
            } 
            //if the node has been previously visited
            //but it has to be visited onthe same path
            else if (pathVis[it]) {
                check[node] = 0;
                return true; // Cycle detected
            }
        }
        
        check[node] = 1;
        pathVis[node] = 0; // Backtracking step
        return false;
    }

public:
    // Function to detect cycle in a directed graph.
   vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int vis[V] = {0};       // Visited array
        int pathVis[V] = {0};   // Path visited array
        int check[V] = {0};
        vector<int> safeNodes;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfsCheck(i, adj, vis, pathVis,check));
                }
            }
            for(int i=0; i<V; i++){
                if(check[i] == 1) safeNodes.push_back(i);
            }
            return safeNodes;
        

    }
};

int main(){
    
    return 0;
}
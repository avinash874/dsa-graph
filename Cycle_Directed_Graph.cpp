#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfsCheck(int node, vector<vector<int>>& adj, int vis[], int pathVis[]) {
        vis[node] = 1;       // Mark the current node as visited
        pathVis[node] = 1;   // Mark the current node as part of the current path

        //Traverse for adjacent nodes
        for (auto it : adj[node]) {
            if (!vis[it]) {
                // when the node is not visited
                if (dfsCheck(it, adj, vis, pathVis)) {
                    return true;
                }
            } 
            //if the node has been previously visited
            //but it has to be visited onthe same path
            else if (pathVis[it]) {
                return true; // Cycle detected
            }
        }

        pathVis[node] = 0; // Backtracking step
        return false;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>>& adj) {
        int vis[V] = {0};       // Visited array
        int pathVis[V] = {0};   // Path visited array

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfsCheck(i, adj, vis, pathVis)) {
                    return true;
                }
            }
        }

        return false; // No cycle found
    }
};

int main(){
    
    return 0;
}
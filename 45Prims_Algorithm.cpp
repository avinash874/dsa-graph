#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int spanningTree(int V, vector<vector<int>> adj[]){
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,greater<pair<int,int>>> pq;

        vector<int> vis(V,0);
        //{wt,node}
        pq.push({0,0});
        int sum = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;

            if(vis[node] == 1) continue;
            //add it to the mst
            vis[node] = 1;
            sum += wt;
            for(auto it : adj[node]){
                int adjNode = it[0];
                int edW = it[1];
                if(!vis[adjNode]){
                    pq.push({edW,adjNode});
                }
            }
        }
        return sum;
    }
};

/*

pseudo code of prim's Algorithm

function spanningTree(V, adj):
    Initialize a min-heap (priority queue) pq
    Initialize a visited array vis of size V with all elements as 0
    Initialize sum = 0 to store the MST weight

    // Start with vertex 0 and weight 0
    Push (0, 0) into pq // (weight, node)

    while pq is not empty:
        // Extract the edge with the smallest weight
        (wt, node) = pq.top()
        pq.pop()

        // If the node is already visited, skip it
        if vis[node] == 1:
            continue

        // Mark the node as visited and add the edge's weight to the MST
        vis[node] = 1
        sum += wt

        // For all adjacent nodes of the current node
        for (adjNode, edW) in adj[node]:
            if vis[adjNode] == 0:
                // Push the edge into the priority queue
                pq.push((edW, adjNode))

    return sum

*/
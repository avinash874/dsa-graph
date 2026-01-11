// Pre-requisite Tasks 

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> topoSort(int V,vector<int> adj[]){
        // vector<int> adj[V];
        // for(auto it : prerequisites){
        //     adj[it.first].push_back(it.second);
        // }
        vector<int> indegree(V, 0);
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            //node is in your topo sort
            //so please remove it from the indegree

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
         }
        return topo;
        
    }
};

/*
Function TopologicalSort(V, adj):
    - Input:
        - V: Number of vertices
        - adj: Adjacency list where adj[u] contains neighbors of vertex u

    1. Create an array `indegree` of size V, initialized to 0
    2. For each vertex u in adj:
         For each neighbor v in adj[u]:
             - Increment indegree[v] by 1 (count incoming edges)

    3. Create an empty queue `q`
    4. For each vertex i in range 0 to V-1:
         - If indegree[i] == 0:
             - Enqueue i into q (vertices with no incoming edges)

    5. Create an empty list `topo` to store the topological order
    6. While q is not empty:
         - Dequeue a vertex u from q
         - Append u to `topo`
         - For each neighbor v in adj[u]:
             - Decrement indegree[v] by 1
             - If indegree[v] == 0:
                 - Enqueue v into q

    7. If size of `topo` == V:
         - Return `topo` (topological order exists)
       Else:
         - Return an empty list (graph contains a cycle, topological order not possible)

*/
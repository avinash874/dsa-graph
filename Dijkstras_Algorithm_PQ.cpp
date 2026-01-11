//  Dijkstra's Algorithm - Using Priority Queue 

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
     vector<int> dijkstra(int V ,vector<vector<int>> adj[], int S) {
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;
        vector<int> dist(V);
        for(int i=0; i<V; i++) dist[i] = 1e9;
            
            
            dist[S] = 0;
            pq.push({0,S});

            while(!pq.empty()){
                int dis = pq.top().first;
                int node = pq.top().second;
                pq.pop();

                for(auto it : adj[node]){
                    int edgeWeight = it[1];
                    int adjNode = it[0];

                    if(dis + edgeWeight < dist[adjNode]){
                        dist[adjNode] = dis + edgeWeight;
                        pq.push({dist[adjNode],adjNode});
                    }
                }
            }
            return dist;
        }
    
};

/*
Function Dijkstra(V, adj, S):
    - Input:
        - V: Number of vertices
        - adj: Adjacency list, where adj[u] contains pairs (v, weight) representing edges
        - S: Source vertex

    1. Initialize distance array `dist`:
        - Set all distances to a very large number (infinity), `dist[i] = ∞` for all i
        - Set `dist[S] = 0` (distance from source to itself is 0)

    2. Create a priority queue `pq` (min-heap):
        - Each element in `pq` is a pair (distance, vertex)
        - Push the source vertex into the queue with distance 0: `pq.push((0, S))`

    3. While `pq` is not empty:
        - Extract the top element `(dis, node)` from the priority queue:
            - `dis` is the current shortest distance to `node`
            - `node` is the vertex being processed

        - For each adjacent vertex `adjNode` of `node` in `adj[node]`:
            - Let `edgeWeight` = weight of edge (node, adjNode)
            - Calculate the tentative distance: `newDist = dis + edgeWeight`

            - If `newDist` is less than `dist[adjNode]`:
                - Update the shortest distance to `adjNode`: `dist[adjNode] = newDist`
                - Push `(newDist, adjNode)` into the priority queue

    4. Return the distance array `dist`

---

### Key Notes
- The adjacency list `adj` is represented as a vector of vectors, where each vector contains pairs `(neighbor, weight)`.
- The priority queue `pq` ensures the vertex with the smallest tentative distance is processed first.
- The algorithm updates the shortest distances dynamically and avoids revisiting nodes unnecessarily, ensuring efficiency.

*/



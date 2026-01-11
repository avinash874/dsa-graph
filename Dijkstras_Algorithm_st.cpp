//  Dijkstra's Algorithm - SET -> data set 
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> dijkstra(int V ,vector<vector<int>> adj[], int S) {
        set<pair<int,int>> st;
        vector<int> dist(V,1e9);
        
            st.insert({0,S});
            dist[S] = 0;

            while(!st.empty()){
                auto it = *(st.begin());
                int node = it.second;
                int dis = it.first;
                st.erase(it);

                for(auto it : adj[node]){
                    int adjNode = it[0];
                    int edgeW = it[1];

                    if(dis + edgeW < dist[adjNode]){
                        if(dist[adjNode] != 1e9)
                            st.erase({dist[adjNode],adjNode});
                            

                            dist[adjNode] = dis + edgeW;
                            st.insert({dist[adjNode],adjNode});
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
        - Set all distances to infinity (`∞`): dist[i] = ∞ for all i
        - Set `dist[S] = 0` (distance from source to itself is 0)

    2. Create an empty set `st`:
        - The set stores pairs `(distance, vertex)`, sorted by distance
        - Insert the source vertex into the set: `st.insert((0, S))`

    3. While `st` is not empty:
        - Extract the first element from the set (smallest distance):
            - Let `(dis, node)` = `st.begin()`
            - Remove `(dis, node)` from the set

        - For each adjacent vertex `adjNode` of `node` in `adj[node]`:
            - Let `edgeW` = weight of edge (node, adjNode)
            - Calculate the tentative distance: `newDist = dis + edgeW`

            - If `newDist < dist[adjNode]`:
                - If `dist[adjNode]` is not infinity (`∞`):
                    - Remove the old `(dist[adjNode], adjNode)` pair from the set

                - Update the shortest distance to `adjNode`: `dist[adjNode] = newDist`
                - Insert the updated pair `(newDist, adjNode)` into the set

    4. Return the distance array `dist`

*/


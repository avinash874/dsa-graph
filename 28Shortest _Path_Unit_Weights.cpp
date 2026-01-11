//28-> Shortest Path in Undirected Graph with Unit Weights
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& edges,int N,int M, int src) {
        vector<int> adj[N];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int dist[N];
        for(int i=0; i<N; i++) dist[i] = 1e9;
            dist[src] = 0;
            queue<int> q;
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(dist[node] + 1 < dist[it]){
                    dist[it] = 1 + dist[node];
                    q.push(it);
                }
            
        }
       vector<int> ans(N,-1);
       for(int i=0; i<N; i++){
        if(dist[i] != 1e9){
            ans[i] = dist[i];
        }
       }
       return ans;
    }
};

int main(){
    
    return 0;
}
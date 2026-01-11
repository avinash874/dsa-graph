#include<iostream>
using namespace std;

class Solution{

    // public:

    // void DFS(vector<int> adj[],int u,vector<bool>& visited,stack<int> &st){
    //     visited[u] = true;

    //     //pahle mere ('u' ke node ke) bachho ko daalo
    //     for(int &v : adj[u]){
    //         if(!visited[v])
    //         DFS(adj,v,visited,st);
    //     }
    //     //ab mujhe daalo stack me
    //     st.push(u);
    // }
    //  vector<int> topoSort(int V,vector<int> adj[]) {
    //     vector<bool> visited(V,false);
    //     stack<int> st;

    //     for(int i=0; i<V; i++){
    //         if(!visited[i])
    //         DFS(adj,i,visited,st);
    //     }
    //     vector<int> result;

    //     while(!st.empty()){
    //         result.push_back(st.top());
    //         st.pop();
    //     }
    //     return result;
    // }

    private:
    void dfs(int node,int vis[],stack<int> &st,vector<int> adj[]){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]) dfs(it,vis,st.adj);
        }
        st.push(node);
    }
    public:
    vector<int> topoSort(int V,vector<int> adj[]){
        int vis[V] = {0};
        stack<int> st ;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
       }

};


/*
Function TopologicalSortDFS(V, adj):
    - Input:
        - V: Number of vertices
        - adj: Adjacency list where adj[u] contains neighbors of vertex u

    1. Create a visited array `visited` of size V, initialized to False
    2. Create an empty stack `st` to store the vertices in topological order

    3. Define a recursive function DFS(node):
         - Mark `node` as visited
         - For each neighbor v in adj[node]:
             - If v is not visited:
                 - Call DFS(v)
         - Push `node` onto the stack

    4. For each vertex i in range 0 to V-1:
         - If `visited[i]` is False:
             - Call DFS(i)

    5. Create an empty list `topo`
    6. While `st` is not empty:
         - Pop the top element from the stack and append it to `topo`

    7. Return `topo` (topological order)

*/
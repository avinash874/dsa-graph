#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> g[N];
bool vis[N];

void dfs(int vertex) {
    /*
    Take action on vertex entering the vertex
    */
    cout << "Entering vertex: " << vertex << endl;
    vis[vertex] = true;
    for (int child : g[vertex]) {
        cout << "Parent: " << vertex << ", Child: " << child << endl;
        if (vis[child]) continue;
        
        // Take action on child before entering the child
        dfs(child);
        
        // Take action on child after exiting the child node
    }
    
    /* Take action on vertex before exiting the vertex */
    cout << "Exiting vertex: " << vertex << endl;
}
 // o(V+E)


int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1); // Add this line for undirected graph
    }

    // Perform DFS from vertex 1 (or any other starting point)
    dfs(1);
}


/*
6 9
1 3 
1 5  
3 5  
3 4 
3 6 
3 2 
2 6 
4 6 
5 6 
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 3, m = 3;
    vector<vector<int>> adj(n + 1); // Adjusted to handle 1-based indexing like in Java.

    // Adding edges
    // Edge 1 --> 2
    adj[1].push_back(2);
    adj[2].push_back(1); // If the graph is undirected, add the reverse edge.

    // Edge 2 --> 3
    adj[2].push_back(3);
    adj[3].push_back(2);

    // Edge 1 --> 3
    adj[1].push_back(3);
    adj[3].push_back(1);

    // Print all edges
    for (int i = 1; i <= n; i++) { // Loop starts from 1 as the graph uses 1-based indexing.
        cout << "Edges from node " << i << ": ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

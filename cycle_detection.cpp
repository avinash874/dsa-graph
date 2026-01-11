#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

bool vis[N];
vector<int> g[N];

bool dfs(int vertex, int parent) {
    vis[vertex] = true;
    for (int child : g[vertex]) {
        if (child == parent) continue; // Skip the edge back to the parent
        if (vis[child]) return true;  // Cycle detected
        if (dfs(child, vertex)) return true; // Check deeper
    }
    return false;
}

int main() {
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    bool isLoopExists = false;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i] && dfs(i, -1)) { // Start DFS for each unvisited component
            isLoopExists = true;
            break;
        }
    }
    cout << (isLoopExists ? "YES" : "NO") << endl; // Output YES if a cycle exists, otherwise NO
    return 0;
}

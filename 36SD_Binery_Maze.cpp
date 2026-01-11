// Shortest Distance in a Binary Maze
#include<bits/stdc++.h>
using namespace std;

// sir ka code

class Solution{
    public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        queue<pair<int,pair<int,int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[source.first][source.second] = 0;
        q.push({0,{source.first,source.second}});
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.first;
            int c = it.second.first;
            for(int i=0; i<4; i++){
                int newr = r + dr[i];
                int newc = c + dc[i];

                if(newr >= 0 && newr < n && newc >= 0 && newc < m
                 && grid[newr][newc] == 1 && dis + 1 < dist[newr][newc]){
                    dist[newr][newc] = 1 + dis;
                    if(newr == destination.first &&
                    newc == destination.second) return dis + 1;
                    q.push({1+dis, {newr,newc}});
                    
                }
            }
        }
        return -1;
    }
};

// Chat GPT se ans in correct formate;

// class Solution {
// public:
//     int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
//         int n = grid.size();
//         int m = grid[0].size();

//         // If the source is the same as the destination
//         if (source == destination) return 0;

//         // Queue for BFS: {distance, {row, column}}
//         queue<pair<int, pair<int, int>>> q;

//         // Distance matrix initialized to infinity
//         vector<vector<int>> dist(n, vector<int>(m, 1e9));
//         dist[source.first][source.second] = 0;

//         // Push the source into the queue
//         q.push({0, {source.first, source.second}});

//         // Directions for moving up, right, down, left
//         int dr[] = {-1, 0, 1, 0};
//         int dc[] = {0, 1, 0, -1};

//         // BFS loop
//         while (!q.empty()) {
//             auto it = q.front();
//             q.pop();

//             int dis = it.first;  // Current distance
//             int r = it.second.first;  // Current row
//             int c = it.second.second;  // Current column

//             for (int i = 0; i < 4; i++) {
//                 int newr = r + dr[i];
//                 int newc = c + dc[i];

//                 // Check boundary conditions and grid constraints
//                 if (newr >= 0 && newr < n && newc >= 0 && newc < m
//                     && grid[newr][newc] == 1 && dis + 1 < dist[newr][newc]) {
                    
//                     dist[newr][newc] = dis + 1;  // Update distance
                    
//                     // If we reach the destination, return the distance
//                     if (newr == destination.first && newc == destination.second) 
//                         return dist[newr][newc];
                    
//                     // Push the new cell into the queue
//                     q.push({dist[newr][newc], {newr, newc}});
//                 }
//             }
//         }

//         // If the destination is not reachable
//         return -1;
//     }
// };


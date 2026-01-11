//  Floyd Warshall Algorithm
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void shortest_distance(vector<vector<int>>&matrix){
        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == -1){
                    matrix[i][j] = 1e9;
                }
                if(i == j) matrix[i][j] = 0;
            }
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    matrix[i][j] = min(matrix[i][j],matrix[i][k] + matrix[k][j]);
                }
            }
        }
        for(int i=0; i<n; i++){
            if(matrix[i][i] < 0){

            }
        }
    for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 1e9){
                    matrix[i][j] = -1;
                }
            }
        }
    }
};

/*
function FloydWarshall(dist, n):
    for k from 0 to n-1:  // k is the intermediate vertex
        for i from 0 to n-1:  // i is the source vertex
            for j from 0 to n-1:  // j is the destination vertex
                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

    return dist

*/

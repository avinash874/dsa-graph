#include<iostream>
using namespace std;
 
class Solution{
    private:
    void dfs(int row,int col,vector<vector<int>> &vis,
    vector<vector<int>>& grid,vector<pair<int,int>>&vec,int row0,int col0){
        vis[row][col] = 1;
        vec.push_back({row-row0,col-col0});
        
        int n = grid.size();
        int m = grid[0].size();
        int delrow[] = {};
        int delcol[] = {};
    }
    public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0))
        set<vector<pair<int,int>>> st;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int,int>> vec;
                    dfs(i,j,grid,vis,vec);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};

int main(){
    
    return 0;
}
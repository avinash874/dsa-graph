// Using BFS algorithm to solve the problem

#include<iostream>
using namespace std;

class Solution{
    private:
    bool check(int start,int V,vector<int>adj[],int color[]){
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it] == color[node]){
                    return false;
                }  
            }
        }
        return true;
    }
    public:
     bool isBipartite(int V,vector<int>adj[]) {
        int color[V];
        for(int i=0; i<V; i++) color[i] = -1;
        for(int i=0; i<V; i++){
            if(color[i] == -1){
                if(check(i,V,adj,color) == false){
                    return false;
                }
            }
        }
        return true;
     }

};

int main(){
    
    return 0;
}
#include<iostream>
using namespace std;

class Solution {
    //wowrks for multiple components
    private:
    //Function to return list containing vertices in Topological order.

	vector<int> topoSort(int V, vector<int> adj[])
	{
		// int indegree[V] = {0};
        vector<int> indegree{V,0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		return topo;
    
	
}
    public:
    string findOrder(vector<string> dict,int N, int k) {
       
        vector<int> adj[k];
        for(int i=0; i<N-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(),s2.size());
            for(int ptr=0; ptr<N; ptr++){
                if(s1[ptr] != s2[ptr]){
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }
        vector<int> topo = topoSort(k,adj);
        string ans = "";
        for(auto it : topo){
            ans = ans + char(it + 'a');
        }
        return ans;
    }
};


int main(){
    
    return 0;
}
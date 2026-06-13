class Solution {
public:
    void dfs(int u, vector<bool> &vis, vector<vector<int>> &adj){
        vis[u]=true;
        for(auto v:adj[u]){
            if(!vis[v]){
                dfs(v,vis,adj);
            }
        }
    }
    void addEdge(int i, int j, vector<vector<int>> &adj){
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    addEdge(i,j,adj);
                }
            }
        }
        int count=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                count++;
            }
        }
        return count;
    }
};
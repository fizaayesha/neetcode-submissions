class Solution {
public:
    vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
    bool isSafe(int i, int j, int n, int m, vector<vector<char>> &grid, vector<vector<bool>> &vis){
        return i>=0 && j>=0 && i<=n-1 && j<=m-1 && grid[i][j]=='1' && !vis[i][j];
    }
    void dfs(int i, int j, int n, int m, vector<vector<char>> & grid, vector<vector<bool>> &vis){
        for(int k=0;k<4;k++){
            int ni=i+dir[k].first;
            int nj=j+dir[k].second;
            if(isSafe(ni,nj,n,m,grid,vis)){
                vis[ni][nj]=true;
                dfs(ni,nj,n,m,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int count=0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isSafe(i,j,n,m,grid,vis)){
                    vis[i][j]=true;
                    dfs(i,j,n,m,grid,vis);
                    count++;
                }
            }
        }
        return count;
    }
};

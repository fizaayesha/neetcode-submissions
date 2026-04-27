class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    bool isSafe(int i,int j, int n, int m,vector<vector<char>> &grid, vector<vector<bool>> &vis){
        return i>=0 && j>=0 && i<=n-1 && j<=m-1 && grid[i][j]=='1' && !vis[i][j];
    }
    void solve(vector<vector<char>> &grid, int n, int m, int i, int j, vector<vector<bool>> &vis){
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int ni=i+dir[k].first;
            int nj=j+dir[k].second;
            if(isSafe(ni,nj,n,m,grid,vis)){
                solve(grid,n,m,ni,nj,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int count=0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    solve(grid,n,m,i,j,vis);
                    count++;
                }
            }
        }
        return count;
    }
};

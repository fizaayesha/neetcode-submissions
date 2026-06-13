class Solution {
public:
    vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
    bool isSafe(int i, int j, int n, int m, vector<vector<char>> &grid){
        return i>=0 && j>=0 && i<=n-1 && j<=m-1 && grid[i][j]=='1';
    }
    void dfs(int i, int j, int n, int m, vector<vector<char>> & grid){
        for(int k=0;k<4;k++){
            int ni=i+dir[k].first;
            int nj=j+dir[k].second;
            if(isSafe(ni,nj,n,m,grid)){
                grid[ni][nj]='0';
                dfs(ni,nj,n,m,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isSafe(i,j,n,m,grid)){
                    grid[i][j]='0';
                    dfs(i,j,n,m,grid);
                    count++;
                }
            }
        }
        return count;
    }
};

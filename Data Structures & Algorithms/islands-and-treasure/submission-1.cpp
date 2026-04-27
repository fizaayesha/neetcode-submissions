class Solution {
public:
    const int INF=2147483647;
    int ans=0;
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    bool isSafe(int i, int j, int n, int m, vector<vector<int>> &grid){
        return i>=0 && j>=0 && i<=n-1 && j<=m-1 && grid[i][j]==INT_MAX; 
    }
    void solve(vector<vector<int>> &grid, int n, int m){
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int i=x.first;
            int j=x.second;
            for(int k=0;k<4;k++){
                int ni=i+dir[k].first;
                int nj=j+dir[k].second;
                if(isSafe(ni,nj,n,m,grid)){
                    grid[ni][nj]=grid[i][j]+1;
                    q.push({ni,nj});
                }
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        solve(grid,n,m);
    }
};

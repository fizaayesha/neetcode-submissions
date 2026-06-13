class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    bool isSafe(int i,int j, int n, int m, vector<vector<int>> &grid, vector<vector<bool>> &vis){
        return i>=0 && j>=0 && i<=n-1 && j<=m-1 && !vis[i][j] && grid[i][j]==1;
    }
    int count=0;
    void bfs(queue<pair<int,int>> &q,int n, int m,vector<vector<bool>>&vis,vector<vector<int>> &grid, int &fresh){
        while(!q.empty() && fresh>0){
            int siz=q.size();
            for(int s=0;s<siz;s++){
                auto x=q.front();
                int i=x.first,j=x.second;
                q.pop();
                for(int k=0;k<4;k++){
                    int ni=i+dir[k].first;
                    int nj=j+dir[k].second;
                    if(isSafe(ni,nj,n,m, grid, vis)){
                        grid[ni][nj]=2;
                        fresh--;
                        q.push({ni,nj});
                    }
                }   
            }
            count++;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size(),m=grid[0].size();
        int fresh=0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1)
                    fresh++;
            }
        }
        if(fresh==0){
            return 0;
        }
        count=0;
        bfs(q,n,m,vis,grid,fresh);
        if(fresh>0){
            return -1;
        }
        return count;
    }
};

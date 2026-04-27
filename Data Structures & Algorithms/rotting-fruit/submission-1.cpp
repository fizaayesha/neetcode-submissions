class Solution {
public:
    vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
    bool isSafe(int i, int j, int n, int m, vector<vector<int>> &grid){
        return i>=0 && j>=0 && i<=n-1 && j<=m-1 && grid[i][j]==1;
    }
    int solve(int n, int m,vector<vector<int>> &grid){
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int minutes=0;
        while(!q.empty() && fresh>0){
            int size=q.size();
            while(size--){
                auto x=q.front();
                int i=x.first;
                int j=x.second;
                q.pop();
                for(int k=0;k<4;k++){
                    int ni=i+dir[k].first;
                    int nj=j+dir[k].second;
                    if(isSafe(ni,nj,n,m,grid)){
                        grid[ni][nj]=2;
                        fresh--;
                        q.push({ni,nj});
                    }
                }
            }
            minutes++;
        }
        return (fresh==0)?minutes:-1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        return solve(n,m,grid);
    }
};

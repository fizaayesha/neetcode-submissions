class Solution {
public:
    vector<vector<int>> dp;
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    bool isSafe(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<=n-1 && j<=m-1;
    }
    int dfs(int i, int j, int n, int m, vector<vector<int>> &matrix){
        int count=1;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        for(int k=0;k<4;k++){
            int ni=i+dir[k].first;
            int nj=j+dir[k].second;
            if(isSafe(ni,nj,n,m) && matrix[ni][nj]>matrix[i][j]){
                count=max(count,1+dfs(ni,nj,n,m,matrix));
            }
        }
        return dp[i][j]=count;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        dp=vector<vector<int>>(n,vector<int>(m,-1));
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(dfs(i,j,n,m,matrix),ans);
            }
        }
        return ans;
    }
};

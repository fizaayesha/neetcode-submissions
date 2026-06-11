class Solution {
public:
    int rec(int n, int m,vector<vector<int>> &dp){
        if(n==0 && m==0){
            return 0;
        }
        if(n==1 || m==1){
            return dp[n][m]=1;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        return dp[n][m]=rec(n-1,m,dp)+rec(n,m-1,dp);
    }
    int tab(int m, int n){
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        for(int j=0;j<n;j++){
            dp[0][j]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return tab(m,n);
    }
};
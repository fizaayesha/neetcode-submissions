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
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return rec(m,n,dp);
    }
};
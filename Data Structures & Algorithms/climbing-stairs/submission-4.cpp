class Solution {
public:
    int rec(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        return rec(n-1)+rec(n-2);
    }
    int memoi(int n,vector<int> &dp){
        if(n<=2){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=memoi(n-1,dp)+memoi(n-2,dp);
    }
    int tab(int n){
        vector<int> dp(n+1,0);
        dp[1]=1,dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return tab(n);
    }
};

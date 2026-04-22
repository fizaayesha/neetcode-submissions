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
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return memoi(n,dp);
    }
};

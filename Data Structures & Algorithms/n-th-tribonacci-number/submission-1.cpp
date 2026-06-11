class Solution {
public:
    int memoi(int n,vector<int> &dp) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(n==2){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=memoi(n-1,dp)+memoi(n-2,dp)+memoi(n-3,dp);
    }
    int tribonacci(int n){
        vector<int> dp(n+1,-1);
        return memoi(n,dp);
    }
};
class Solution {
public:
    int solve(vector<int> &prices, int ind, int n, int buy,vector<vector<int>> &dp){
        if(ind>=n){
            return 0;
        }
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        if(buy==1){
            dp[ind][buy]=max(solve(prices,ind+1,n,1,dp),solve(prices,ind+1,n,0,dp)-prices[ind]);
        }
        else{
            dp[ind][buy]=max(solve(prices,ind+1,n,0,dp),solve(prices,ind+2,n,1,dp)+prices[ind]);
        }
        return dp[ind][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(prices,0,n,1,dp);
    }
};

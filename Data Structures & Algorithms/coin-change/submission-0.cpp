class Solution {
public:
    int rec(vector<int> &coins, int amount,int n,vector<vector<int>> &dp){
        if(amount==0){
            return 0;
        }
        if(n==0){
            return 1e9;
        }
        if(dp[n][amount]!=-1){
            return dp[n][amount];
        }
        if(coins[n-1]>amount){
            return dp[n][amount]=rec(coins,amount,n-1,dp);
        }
        return dp[n][amount]=min(rec(coins,amount,n-1,dp),1+rec(coins,amount-coins[n-1],n,dp));
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int ans= rec(coins,amount,n,dp);
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};

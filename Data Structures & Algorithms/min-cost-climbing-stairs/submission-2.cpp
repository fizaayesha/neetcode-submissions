class Solution {
public:
    int mini=INT_MAX;
    void rec(vector<int> &cost, int ind, int n, int ans){
        if(ind>=n){
            mini=min(mini,ans);
            return;
        }
        rec(cost,ind+1,n,ans+cost[ind]);
        rec(cost,ind+2,n,ans+cost[ind]);
    }
    int memoi(vector<int> &cost, int ind, int n, vector<int> &dp){
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int one=memoi(cost,ind+1,n,dp);
        int two=memoi(cost,ind+2,n,dp);
        return dp[ind]=min(one,two)+cost[ind];
    }
    int tab(vector<int> &cost, int n){
        vector<int> dp(n+1,0);
        for(int i=2;i<=n;i++){
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        // vector<int> dp(n+1,-1);
        // return min(memoi(cost,0,n,dp),memoi(cost,1,n,dp));
        return tab(cost,n);
    }
};

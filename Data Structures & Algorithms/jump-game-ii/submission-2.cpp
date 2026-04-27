class Solution {
public:
    int rec(vector<int> &nums, int ind, int n,vector<int> &dp){
        if(ind>=n-1){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int mini=INT_MAX;
        for(int i=1;i<=nums[ind];i++){
            if(ind+i<n){
                int jumps=rec(nums,ind+i,n,dp);
                if(jumps!=INT_MAX){
                    mini=min(mini,1+jumps);
                }
            }
        }
        return dp[ind]=mini;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return rec(nums,0,nums.size(),dp);
    }
};

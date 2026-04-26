class Solution {
public:
    bool solve(int target,vector<int> &nums, int n,vector<vector<int>> &dp){
        if(n==0){
            if(target==0){
                return true;
            }
            else{
                return false;
            }
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        bool notPick=solve(target,nums,n-1,dp);
        bool pick=false;
        if(nums[n-1]<=target){
            pick= solve(target-nums[n-1],nums,n-1,dp);
        }
        return dp[n][target]=pick || notPick;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int target=sum/2;
        if(sum%2!=0){
            return false;
        }
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solve(target,nums,n,dp);
    }
};

class Solution {
public:
    int rec(vector<int> &nums, int n){
        if(n==0){
            return nums[0];
        }
        if(n<0){
            return 0;
        }
        int include=nums[n]+rec(nums,n-2);
        int exclude=rec(nums,n-1);
        return max(include,exclude);
    }
    int memoi(vector<int> &nums, int n, vector<int> &dp){
        if(n==0){
            dp[n]=nums[0];
            return dp[n];
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int include=nums[n]+memoi(nums,n-2,dp);
        int exclude=memoi(nums,n-1,dp);
        return dp[n]=max(include,exclude);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return memoi(nums,n-1,dp);
    }
};

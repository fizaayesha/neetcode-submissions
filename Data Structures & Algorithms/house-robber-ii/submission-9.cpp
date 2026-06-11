class Solution {
public:
    int rec(int start, int n, vector<int> &nums,vector<int>&dp){
        if(n<start){
            return 0;
        }
        if(n==start){
            return nums[start];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=max(nums[n]+rec(start,n-2,nums,dp),rec(start,n-1,nums,dp));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> dp1(n,-1),dp2(n,-1);
        return max(rec(0,n-2,nums,dp1),rec(1,n-1,nums,dp2));
    }
};

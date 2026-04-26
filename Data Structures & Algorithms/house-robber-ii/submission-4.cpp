class Solution {
public:
    int rec(int start, vector<int> &nums, int n){
        if(n<start){
            return 0;
        }
        if(n==start){
            return nums[start];
        }
        return max(nums[n]+rec(start,nums,n-2),rec(start,nums,n-1));
    }
    int memoi(int start,vector<int>&nums, int n, vector<int> &dp){
        if(n<start){
            return 0;
        }
        if(n==start){
            return dp[n]=nums[start];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=max(nums[n]+memoi(start,nums,n-2,dp),memoi(start,nums,n-1,dp));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        return max(memoi(1,nums,n-1,dp1),memoi(0,nums,n-2,dp2));
    }
};

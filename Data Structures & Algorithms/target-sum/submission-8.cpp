class Solution {
public:
    int count=0;
    void rec(vector<int> &nums, int target, int k, int n){
        if(n==0){
            if(k==target){
                count++;
            }
            return;
        }
            rec(nums,target,k+nums[n-1],n-1);
            rec(nums,target,k-nums[n-1],n-1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int k=0;
        rec(nums,target,k,n);
        return count;
    }
};

class Solution {
public:
    bool solve(vector<int> &nums, vector<bool> &vis, int target, int currSum, int ind, int n, int k){
        if(k==1){
            return true;
        }
        if(currSum==target){
            return solve(nums,vis,target,0,0,n,k-1);
        }
        if(ind==nums.size()){
            return false;
        }
        if(nums[ind]<=target-currSum && !vis[ind]){
            vis[ind]=true;
            if(solve(nums,vis,target,currSum+nums[ind],ind+1,n,k)){
                return true;
            }
            vis[ind]=false;
        }
        return solve(nums,vis,target,currSum,ind+1,n,k);
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k!=0){
            return false;
        }
        int target=sum/k;
        vector<bool> vis(nums.size(),false);
        return solve(nums,vis,target,0,0,nums.size(),k);
    }
};
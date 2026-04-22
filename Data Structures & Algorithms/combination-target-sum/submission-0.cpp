class Solution {
public:
    void solve(vector<int> &nums, int target, vector<int> &demo, vector<vector<int>> &ans, int n, int i){
        if(accumulate(demo.begin(),demo.end(),0)==target){
            ans.push_back(demo);
            return;
        }
        if(i>=n || accumulate(demo.begin(),demo.end(),0)>target){
            return;
        }
        demo.push_back(nums[i]);
        solve(nums,target,demo,ans,n,i);
        demo.pop_back();
        solve(nums,target,demo,ans,n,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> demo;
        vector<vector<int>> ans;
        solve(nums,target,demo,ans,n,0);
        return ans;
    }
};

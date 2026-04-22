class Solution {
public:
    void solve(vector<int> &nums, vector<int> &demo, vector<vector<int>> &ans, int target,int n, int ind){
        if(accumulate(demo.begin(),demo.end(),0)==target){
            ans.push_back(demo);
            return;
        }
        if(ind>=n || accumulate(demo.begin(),demo.end(),0)>target){
            return;
        }
        for(int i=ind;i<n;i++){
            if(i>ind && nums[i]==nums[i-1]){
                continue;
            }
            demo.push_back(nums[i]);
            solve(nums,demo,ans,target,n,i+1);
            demo.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int> demo;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        solve(candidates,demo,ans,target,n,0);
        return ans;
    }
};

class Solution {
public:
    void solve(vector<int> &demo, vector<vector<int>> &ans, vector<int> &nums, int n, int ind){
            ans.push_back(demo);
        
        for(int i=ind;i<n;i++){
            demo.push_back(nums[i]);
            solve(demo,ans,nums,n,i+1);
            demo.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> demo;
        solve(demo,ans,nums,nums.size(),0);
        return ans;
    }
};

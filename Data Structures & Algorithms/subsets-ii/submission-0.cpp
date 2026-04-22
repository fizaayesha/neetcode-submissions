class Solution {
public:
    set<vector<int>> mp;
    void solve(vector<int> &nums,vector<int> demo, vector<vector<int>> &ans, int ind, int n){
        if(mp.find(demo)==mp.end()){
            ans.push_back(demo);
            mp.insert(demo);
        }
        if(ind>=n){
            return;
        }
        for(int i=ind;i<n;i++){
            demo.push_back(nums[i]);
            solve(nums,demo,ans,i+1,n);
            demo.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<int> demo;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        solve(nums,demo,ans,0,n);
        return ans;
    }
};

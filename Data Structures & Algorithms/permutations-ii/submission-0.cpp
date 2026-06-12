class Solution {
public:
    void solve(int n, int ind, vector<int> &nums,vector<vector<int>> &ans,set<vector<int>> &mp){
        if(ind==n){
            if(mp.find(nums)==mp.end()){
                ans.push_back(nums);
                mp.insert(nums);
            }
            return;
        }
        for(int i=ind;i<n;i++){
            swap(nums[i],nums[ind]);
            solve(n,ind+1,nums,ans,mp);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> mp;
        int n=nums.size();
        solve(n,0,nums,ans,mp);
        return ans;
    }
};
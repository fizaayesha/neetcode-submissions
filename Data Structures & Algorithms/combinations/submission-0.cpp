class Solution {
public:
    void solve(int k, int n, vector<int> demo, vector<vector<int>> &ans, vector<int> &arr, int ind){
        if(demo.size()==k){
            ans.push_back(demo);
            demo.clear();
            return;
        }
        for(int i=ind;i<n;i++){
            demo.push_back(arr[i]);
            solve(k,n,demo,ans,arr,i+1);
            demo.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> arr(n);
        vector<int> demo;
        vector<vector<int>> ans;
        int ind=0;
        for(int i=0;i<n;i++){
            arr[i]=i+1;
        }
        solve(k,n,demo,ans,arr,ind);
        return ans;
    }
};
// 1 2 3
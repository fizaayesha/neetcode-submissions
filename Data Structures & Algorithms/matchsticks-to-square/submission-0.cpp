class Solution {
public:
    bool solve(int k, int target,vector<bool>&vis,vector<int> &arr,int n, int ind,int curr){
        if(k==1){
            return true;
        }
        if(curr==target){
            return solve(k-1,target,vis,arr,n,0,0);
        }
        if(ind==arr.size()){
            return false;
        }
        if(arr[ind]<=target-curr && !vis[ind]){
            vis[ind]=true;
            if(solve(k,target,vis,arr,n,ind+1,curr+arr[ind])){
                return true;
            }
            vis[ind]=false;
        }
        return solve(k,target,vis,arr,n,ind+1,curr);
    }
    bool makesquare(vector<int>& matchsticks) {
        int n=matchsticks.size();
        int sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4!=0){
            return false;
        }
        int target=sum/4;
        int k=4;
        vector<bool> vis(n,false);
        return solve(k,target,vis,matchsticks,n,0,0);
    }
};
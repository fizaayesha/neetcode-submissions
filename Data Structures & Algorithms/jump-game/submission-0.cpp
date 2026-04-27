class Solution {
public:
    bool rec(vector<int> &nums, int ind, int n){
        if(ind>=n-1){
            return true;
        }
        if(nums[ind]==0){
            return false;
        }
        for(int i=1;i<=nums[ind];i++){
            if(rec(nums,ind+i,n)){
                return true;
            }
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        return rec(nums,0,n);
    }
};

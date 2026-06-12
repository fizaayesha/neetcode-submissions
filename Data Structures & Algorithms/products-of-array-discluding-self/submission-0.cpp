class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int pro=1;
        int zero=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero++;
            }
            if(nums[i]!=0){
                pro*=nums[i];
            }
        }
        for(int i=0;i<n;i++){
            if(zero>1){
                ans.push_back(0);
            }
            else if(zero==1){
                if(nums[i]==0){
                    ans.push_back(pro);
                }
                else{
                    ans.push_back(0);
                }
            }
            else{
                ans.push_back(pro/nums[i]);
            }
        }
        return ans;
    }
};
// -1 0 1 2 3
// zero=1,pro=-6

// -1 0 0 2 3
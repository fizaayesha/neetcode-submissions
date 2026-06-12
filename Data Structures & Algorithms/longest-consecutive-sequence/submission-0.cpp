class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        int maxi=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=nums[i];
            if(mp.find(x)!=mp.end() && mp.find(x-1)==mp.end()){
                int curr=x;
                int count=0;
                while(mp.find(curr)!=mp.end()){
                    mp.erase(curr); 
                    count++;
                    curr++;
                }
                maxi=max(maxi,count);
            }
        }
        return maxi;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int n=s.length();
        int i=0,j=0,maxi=0;
        while(j<n){
            mp[s[j]]++;
            if(mp.size()==j-i+1){
                maxi=max(maxi,j-i+1);
                j++;
            }
            else{
                while(mp[s[j]]>1){
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
                if(mp.size()==j-i+1){
                    maxi=max(maxi,j-i+1);
                }
                j++;
            }
        }
        return maxi;
    }
};

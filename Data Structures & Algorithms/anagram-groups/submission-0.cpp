class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n=strs.size();
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<n;i++){
            vector<int> freq(26,0);
            for(auto x:strs[i]){
                freq[x-'a']++;
            }
            string key="";
            for(int i=0;i<26;i++){
                key+="#"+to_string(freq[i]);
            }
            mp[key].push_back(strs[i]);
        }
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};

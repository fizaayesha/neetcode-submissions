class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void solve(vector<vector<string>> &ans, vector<string> &demo, string s, int ind){
        if(ind==s.length()){
            ans.push_back(demo);
            return;
        }
        for(int i=ind;i<s.length();i++){
            string str=s.substr(ind,i-ind+1);
            if(isPalindrome(str,0,str.length()-1)){
                demo.push_back(str);
                solve(ans,demo,s,i+1);
                demo.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> demo;
        vector<vector<string>> ans;
        solve(ans,demo,s,0);
        return ans;
    }
};

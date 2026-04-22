class Solution {
public:
    vector<string> str={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(string digits,vector<string> &ans, string demo, int n, int ind){
        if(demo.length()==n){
            ans.push_back(demo);
            return;
        }
        for(int i=0;i<str[digits[ind]-'0'].length();i++){
            demo.push_back(str[digits[ind]-'0'][i]);
            solve(digits,ans,demo,n,ind+1);
            demo.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string demo;
        int n=digits.length();
        vector<string> ans;
        if(n==0){
            return {};
        }
        solve(digits,ans,demo,n,0);
        return ans;
    }
};

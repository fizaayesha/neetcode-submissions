class Solution {
public:
    void solve(int open, int close, int n, vector<string> &ans, string demo){
        if(open==0 && close==0){
            ans.push_back(demo);
            return;
        }
        if(close < open || open < 0 || close < 0){
            return;
        }
        solve(open-1,close,n,ans,demo+'(');
        solve(open,close-1,n,ans,demo+')');
    }
    vector<string> generateParenthesis(int n) {
        int open=n,close=n;
        string demo;
        vector<string> ans;
        solve(open,close,n,ans,demo);
        return ans;
    }
};
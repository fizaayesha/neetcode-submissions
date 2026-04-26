class Solution {
public:
    bool solve1(int start, int end, string s, vector<vector<int>> &dp){
        if(start>=end){
            return true;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        if(s[start]!=s[end]){
            dp[start][end]=0;
            return false;
        }
        dp[start][end]=solve1(start+1,end-1,s,dp);
        return dp[start][end];
    }
    void solve2(string &s, int ind, int &count, vector<vector<int>> &dp){
        int n=s.length();
        for(int i=ind;i<n;i++){
            if(solve1(ind,i,s,dp)){
                count++;
            }
        }
    }
    int countSubstrings(string s) {
        int n=s.length();
        int count=0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            solve2(s,i,count,dp);
        }
        return count;
    }
};

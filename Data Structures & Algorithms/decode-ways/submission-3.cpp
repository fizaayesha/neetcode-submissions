class Solution {
public:
    int rec(string s, int n, int ind,vector<int> &dp){
        if(s[ind]=='0' || n==0){
            return 0;
        }
        if(ind==n){
            return dp[n]=1;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int pick=rec(s,n,ind+1,dp);
        int notPick=0;
        if(ind+1<n){
            int nums=stoi(s.substr(ind,2));
            if(nums>=10 && nums<=26){
                notPick=rec(s,n,ind+2,dp);
            }
        }
        return dp[ind]=pick+notPick;
    }
    int numDecodings(string s) {
        vector<int> dp(s.length()+1,-1);
        return rec(s,s.length(),0,dp);
    }
};

class Solution {
public:
    int rec(string s1,string s2, int n, int m){
        if(n==0 || m==0){
            return 0;
        }
        if(s1[n-1]==s2[m-1]){
            return 1+rec(s1,s2,n-1,m-1);
        }
        else{
            return max(rec(s1,s2,n-1,m),rec(s1,s2,n,m-1));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(),m=text2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
        // return rec(text1,text2,n,m);
    }
};

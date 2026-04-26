class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        string t=s;
        reverse(t.begin(),t.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        int maxi=0,end=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    int rev=n-j;
                    if(i-dp[i][j]==rev){
                        if(dp[i][j]>maxi){
                            maxi=dp[i][j];
                            end=i-1;
                        }
                    }
                }
            }
        }
        return s.substr(end-maxi+1,maxi);
    }
};

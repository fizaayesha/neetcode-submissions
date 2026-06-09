class Solution {
public:
    string commonPrefix(string s, string t, int n, int m){
        string ans;
        int i=0;
        while(i<n && i<m){
            if(s[i]!=t[i]){
                break;
            }
            ans.push_back(s[i]);
            i++;
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int mini=INT_MAX;
        if(strs.size()==1){
            return strs[0];
        }
        string s=strs[0];
        for(int i=1;i<strs.size();i++){
            string t=strs[i];
            string ans=commonPrefix(s,t,s.length(),t.length());
            cout<<"Prefix btw: "<<s<<" and "<<t<<" is: "<<ans<<endl;
            s=ans;
        }
        return s;
    }
};
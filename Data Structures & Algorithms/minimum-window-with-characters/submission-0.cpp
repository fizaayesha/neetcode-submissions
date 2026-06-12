class Solution {
public:
    string minWindow(string s, string t) {
        int i=0,j=0,mini=INT_MAX;
        map<char,int> mp;
        int ind=0;
        int n=s.length(),m=t.length();
        int count=m;
        for(auto x:t){
            mp[x]++;
        }
        while(j<n){
            if(mp[s[j]]>0){
                count--;
            }
            mp[s[j]]--;
            j++;
            while(count==0){
                if(j-i<mini){
                    ind =i;
                    mini=j-i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    count++;
                }
                i++;
            }
        }
        return mini==INT_MAX?"":s.substr(ind,mini);
    }
};

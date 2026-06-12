class Solution {
public:
    void solve(vector<string>&ans,string &s, unordered_set<string> &st,int ind, vector<string> temp){
        if(ind==s.length()){
            string sen;
            for(int j=0;j<temp.size();j++){
                sen+=temp[j];
                if(j!=temp.size()-1){
                    sen+=" ";
                }
            }
            ans.push_back(sen);
            return;
        }
        string word;
        for(int i=ind;i<s.length();i++){
            word+=s[i];
            if(st.find(word)!=st.end()){
                temp.push_back(word);
                solve(ans,s,st,i+1,temp);
                temp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        vector<string>ans;
        vector<string> temp;
        solve(ans,s,st,0,temp);
        return ans;
    }
};
class Solution {
public:
    bool isSafe(int i, int j, int n, vector<string> &demo){
        int ni=i,nj=j;
        while(j>=0 && i>=0){
            if(demo[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
        i=ni,j=nj;
        while(i<n && j>=0){
            if(demo[i][j]=='Q'){
                return false;
            }
            i++;
            j--;
        }
        i=ni,j=nj;
        while(j>=0){
            if(demo[i][j]=='Q'){
                return false;
            }
            j--;
        }
        return true;
    }
    void solve(int j, int n, vector<vector<string>> &queens, vector<string> &demo){
        if(j==n){
            queens.push_back(demo);
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(i,j,n,demo)){
                demo[i][j]='Q';
                solve(j+1,n,queens,demo);
                demo[i][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> demo;
        vector<vector<string>> queens;
        string s(n,'.');
        for(int i=0;i<n;i++){
            demo.push_back(s);
        }
        solve(0,n,queens,demo);
        return queens;
    }
};

class Solution {
public:
    int count=0;
    bool isSafe(int i, int j, int n, vector<string> &demo){
        int ni=i,nj=j;
        while(i>=0 && j>=0){
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
    void solve(int j, int n, vector<string> &demo){
        if(j==n){
            count++;
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(i,j,n,demo)){
                demo[i][j]='Q';
                solve(j+1,n,demo);
                demo[i][j]='.';

            }
        }
    }
    int totalNQueens(int n) {
        vector<string> demo;
        string s(n,'.');
        for(int i=0;i<n;i++){
            demo.push_back(s);
        }
        solve(0,n,demo);
        return count;
    }
};
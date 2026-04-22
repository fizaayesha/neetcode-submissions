class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    bool isSafe(int i,int j, int n, int m, vector<vector<bool>> &vis){
        return i>=0 && j>=0 && i<=n-1 && j<=m-1 && !vis[i][j];
    }
    bool solve(vector<vector<char>> &board, string word, int i, int j, int n, int m, int ind, vector<vector<bool>> &vis){
        if(ind==word.length()){
            return true;
        }
        for(int k=0;k<4;k++){
            int ni=i+dir[k].first;
            int nj=j+dir[k].second;
            if(isSafe(ni,nj,n,m,vis) && board[ni][nj]==word[ind]){
                vis[ni][nj]=true;                
                if(solve(board,word,ni,nj,n,m,ind+1,vis)){
                    return true;
                }
                vis[ni][nj]=false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=true;
                    if(solve(board,word,i,j,n,m,1,vis)){
                        return true;
                    }
                    vis[i][j]=false;
                }
            }
        }
        return false;
    }
};

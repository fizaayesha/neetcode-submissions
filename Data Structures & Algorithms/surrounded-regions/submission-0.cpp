class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    bool isSafe(int i, int j, int n, int m, vector<vector<bool>> &vis, vector<vector<char>> &board){
        return i>=0 && j>=0 && i<n && j<m && !vis[i][j] && board[i][j]=='O';
    }
    void dfs(vector<vector<char>>& board,vector<vector<bool>> &vis, int i, int j, int n, int m) {
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int ni=i+dir[k].first;
            int nj=j+dir[k].second;
            if(isSafe(ni,nj,n,m,vis,board)){
                dfs(board,vis,ni,nj,n,m);
            }
        }
    }
    void solve(vector<vector<char>>& board){
        int n=board.size(),m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j]=='O'){
                    dfs(board,vis,i,j,n,m);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};

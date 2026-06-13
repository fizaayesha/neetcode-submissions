class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    bool isSafe(int i, int j, int n, int m, vector<vector<int>> &image, vector<vector<bool>> &vis, int org){
        return i>=0 && j>=0 && i<=n-1 & j<=m-1 && image[i][j]==org && !vis[i][j];
    }
    void dfs(int i, int j, int n, int m, vector<vector<int>> &image, vector<vector<bool>> &vis, int color, int org){
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int ni=i+dir[k].first;
            int nj=j+dir[k].second;
            if(isSafe(ni,nj,n,m,image,vis,org)){
                image[ni][nj]=color;
                dfs(ni,nj,n,m,image,vis,color,org);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(),m=image[0].size();
        int org=image[sr][sc];
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        if(sr>=0 && sc>=0 && sr<=n-1 && sc<=m-1){
            image[sr][sc]=color;
            dfs(sr,sc,n,m,image,vis,color,org);
        }
        return image;
    }
};
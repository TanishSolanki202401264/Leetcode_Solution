class Solution {
public:
    void bfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&vis){
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        vis[row][col]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            int r=cur.first;
            int c=cur.second;

            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];

                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]=='1' && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //Jo island male and te visited na hoy to tena upper BFS apply karvanu and tene visit karvano 
                if(grid[i][j]=='1' && !vis[i][j]){
                    count++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};

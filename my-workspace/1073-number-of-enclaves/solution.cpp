class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
          int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

             for(int i=0;i<m;i++){
           if(grid[i][0]==1 && !vis[i][0]){
            q.push({i,0});
            vis[i][0]=1;
           }
        
          if(grid[i][n-1]==1 && !vis[i][n-1]){
            q.push({i,n-1});
            vis[i][n-1]=1;
          }
        }

        for(int j=0;j<n;j++){
            if(grid[0][j]==1 && !vis[0][j]){
                q.push({0,j});
                vis[0][j]=1;
            }
            if(grid[m-1][j]==1 && !vis[m-1][j]){
                q.push({m-1,j});
                vis[m-1][j]=1;
            }
        }
           while(!q.empty()){
        auto cur=q.front();
        q.pop();
        int row=cur.first;
        int col=cur.second;
        for(int k=0;k<4;k++){
            int nr=row+dr[k];
            int nc=col+dc[k];
            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1 && !vis[nr][nc]){
                vis[nr][nc]=1;
                q.push({nr,nc});
            }
        }
       }
       int count=0;
         for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1 && !vis[i][j]){
               count++;
            }
        }
      }
      return count;
    }
};

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
       bool found=0;
       for(int i=0;i<m && !found;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                q.push({i,j});
                vis[i][j]=1;
                found=1;
                break;
            }
        }
       }
       int perimeter=0;
       while(!q.empty()){
        auto it=q.front();
        q.pop();

        int row=it.first;
        int col=it.second;
        for(int k=0;k<4;k++){
            int nr=row+dr[k];
            int nc=col+dc[k];

          //grid ni bahar hoy jo to 
            if(nr<0 || nr>=m || nc<0 || nc>=n){
                perimeter++;
            }
            //jo water hoy to 
           else  if(grid[nr][nc]==0){
                perimeter++;
            }
            //jo land hoy to
          else if(!vis[nr][nc]){
            vis[nr][nc]=1;
            q.push({nr,nc});
          }
        }
       }
       return perimeter;
    }
};

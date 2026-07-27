class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
//badha j zero ne queue ma nakhoo and jo te visited na hoy to te place ne visit karo sarkhii rite 
        for(int i=0;i<m;i++){
           if(board[i][0]=='O' && !vis[i][0]){
            q.push({i,0});
            vis[i][0]=1;
           }
        
          if(board[i][n-1]=='O' && !vis[i][n-1]){
            q.push({i,n-1});
            vis[i][n-1]=1;
          }
        }

        for(int j=0;j<n;j++){
            if(board[0][j]=='O' && !vis[0][j]){
                q.push({0,j});
                vis[0][j]=1;
            }
            if(board[m-1][j]=='O' && !vis[m-1][j]){
                q.push({m-1,j});
                vis[m-1][j]=1;
            }
        }
       //Have MULTISOURCE BFS no use karta:
       while(!q.empty()){
        auto cur=q.front();
        q.pop();
        int row=cur.first;
        int col=cur.second;
        for(int k=0;k<4;k++){
            int nr=row+dr[k];
            int nc=col+dc[k];

            if(nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc]=='O' && !vis[nr][nc]){
                vis[nr][nc]=1;
                q.push({nr,nc});
            }
        }
       }
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='O' && !vis[i][j]){
                board[i][j]='X';
            }
        }
      }
    }
};

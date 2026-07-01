class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            int x=cur.first;
            int y=cur.second;
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && ny>=0 && nx<n && ny<n && dist[nx][ny]==-1){
                    dist[nx][ny]=dist[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        auto check=[&](int val){
            if(dist[0][0]<val)
                return false;
            vector<vector<int>> vis(n,vector<int>(n,0));
            queue<pair<int,int>> qu;
            qu.push({0,0});
            vis[0][0]=1;
            while(!qu.empty()){
                auto cur=qu.front();
                qu.pop();
                int x=cur.first;
                int y=cur.second;
                if(x==n-1 && y==n-1)
                    return true;
                for(int k=0;k<4;k++){
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(nx>=0 && ny>=0 && nx<n && ny<n
                       && !vis[nx][ny]
                       && dist[nx][ny]>=val){
                        vis[nx][ny]=1;
                        qu.push({nx,ny});
                    }
                }
            }
            return false;
        };
        int low=0;
        int high=2*n;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(mid))
                low=mid+1;
            else
                high=mid-1;
        }
        return high;
    }
};

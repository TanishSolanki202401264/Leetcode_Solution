class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>>dist(m,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            //jeni jeni value zero hoy temne queue ma nakhii do pahele thii j and temni mate ans pan zero j aavse 
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            int row=cur.first;
            int col=cur.second;
            for(int k=0;k<4;k++){
                int nr=row+dr[k];
                int nc=col+dc[k];
                if(nr>=0 && nr<m && nc>=0 && nc<n && dist[nr][nc]==-1){
                     dist[nr][nc]=dist[row][col]+1;
                     q.push({nr,nc});
                }
                //jya sudhii dist[nr][nc]==-1 na rahe tya sudhii apde aa process mathii pass thavu padse 
            }
        }
       return dist;
    }
};

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int oldc=image[sr][sc];
        if(oldc==color){
            return image;
        }
        //ahiya apde badha j kam queue banavine j karvana rahse 
        queue<pair<int,int>>q;
        q.push({sr,sc});

        image[sr][sc]=color;

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!q.empty()){
            auto it=q.front();
            q.pop();

            int row=it.first;
            int col=it.second;

            for(int k=0;k<4;k++){
                int nr=row+dr[k];
                int nc=col+dc[k];

                if(nr>=0 && nr<m && nc>=0 && nc<n && image[nr][nc]==oldc){
                    image[nr][nc]=color;
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};

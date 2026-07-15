class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int dfs(vector<vector<int>>& grid,int i,int j,int remain)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n)
            return 0;
        if(grid[i][j]==-1 || grid[i][j]==-2)
            return 0;
        if(grid[i][j]==2)
        {
            if(remain==1)
                return 1;
            return 0;
        }
        int temp=grid[i][j];
        grid[i][j]=-2;
        int ans=0;
        for(int k=0;k<4;k++)
        {
            int ni=i+dx[k];
            int nj=j+dy[k];
            ans+=dfs(grid,ni,nj,remain-1);
        }
        grid[i][j]=temp;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid)
    {
        int sx,sy;
        int remain=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]!=-1)
                    remain++;
                if(grid[i][j]==1)
                {
                    sx=i;
                    sy=j;
                }
            }
        }
        return dfs(grid,sx,sy,remain);
    }
};

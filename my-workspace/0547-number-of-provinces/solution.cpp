class Solution {
public:
    void dfs(int node,
             vector<vector<int>>& isConnected,
             vector<int>& visited)
    {
        visited[node]=1;
        for(int neighbour=0;
            neighbour<isConnected.size();
            neighbour++)
        {
            if(isConnected[node][neighbour]==1
               &&
               !visited[neighbour])
            {
                dfs(neighbour,
                    isConnected,
                    visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n=isConnected.size();
        vector<int>visited(n,0);
        int province=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,
                    isConnected,
                    visited);
                province++;
            }
        }
        return province;
    }
};

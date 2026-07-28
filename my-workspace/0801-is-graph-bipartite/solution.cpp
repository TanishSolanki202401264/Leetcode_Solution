class Solution {
public:
    bool dfs(int node,int col,vector<vector<int>>&graph,vector<int>&color){
        color[node]=col;
        for(int neighbour:graph[node]){
            if(color[neighbour]==-1){
              if(!dfs(neighbour,1-col,graph,color)){
                return 0;
              }
            }
            else if(color[neighbour]==color[node]){
                return 0;
            }
        }
    
    return 1;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(!dfs(i,0,graph,color)){
                    return 0;
                }
            }
        }
        return 1;
        //badha j node mate check karvanu ke teno je neighbour chee te tenathii opposite color no chee ke nahi ke pachii same color no chee aa confusion dur karva mate badha j node i=0 thii i<V mate bfs lagadvanu
    }
};

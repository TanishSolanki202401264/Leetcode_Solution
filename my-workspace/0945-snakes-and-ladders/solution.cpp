class Solution {
public:
     pair<int,int>getPosition(int cell,int n){
            int rowFromBottom=(cell-1)/n;

            int row=n-1-rowFromBottom;
            int col=(cell-1)%n;

            if(rowFromBottom%2==1){
                col=n-1-col;
            }
            return {row,col};
        }
    int snakesAndLadders(vector<vector<int>>& board) {
       int n=board.size();
      int N=n*n;

      queue<int>q;
      vector<int>dist(N+1,-1);

      q.push(1);
      dist[1]=0;

      while(!q.empty()){
        int curr=q.front();
        q.pop();

        for(int dice=1;dice<=6;dice++){
            int next=curr+dice;
            
            if(next>N){
                continue;
            }

            auto [row,col]=getPosition(next,n);

            if(board[row][col]!=-1){
                next=board[row][col];
            }

            if(dist[next]==-1){
                dist[next]=dist[curr]+1;

                if(next==N){
                    return dist[next];
                }
                q.push(next);
            }
        }
      }



    return -1;
    }
};

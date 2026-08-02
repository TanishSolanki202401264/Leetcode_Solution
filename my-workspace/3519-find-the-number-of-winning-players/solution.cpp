class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        //saav easy problem kahii shakay chee simple grid no use karine solve thai jashe 
        //aaram thii 
        int cnt[10][11]={};
        for(auto &it:pick){
            cnt[it[0]][it[1]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int color=0;color<=10;color++){
                if(cnt[i][color]>i){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int minimumPushes(string word) {
       int n=word.size();
       int cost=0;
       for(int i=0;i<n;i++){
         if(i>=0 && i<8){
            cost=cost+1;
         }
        else if(i>=8 && i<16){
            cost=cost+2;
         }
        else if(i>=16 && i<24){
            cost=cost+3;
         }
        else  if(i>=24 && i<26){
            cost=cost+4;
        }
       }
       return cost;
    }
};

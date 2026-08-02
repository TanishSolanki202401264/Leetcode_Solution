class Solution {
public:
    string winningPlayer(int x, int y) {
        int a=x/1;
        int b=y/4;
        int ans=min(a,b);
        if(ans%2==0){
            return "Bob";
        }
        else{
            return "Alice";
        }
    }
};

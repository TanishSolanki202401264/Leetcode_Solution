class Solution {
public:
    bool consecutiveSetBits(int n) {
        int answer=0;
        while(n>0){
            if((n&3)==3){
                answer++;
            }
            n>>=1;
        }
        return answer==1;
    }
};

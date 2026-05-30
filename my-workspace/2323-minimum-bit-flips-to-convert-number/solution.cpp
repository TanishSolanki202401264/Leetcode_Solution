class Solution {
public:
    int minBitFlips(int start, int goal) {
        int answer=start^goal;

        int count=0;
        for(int i=0;i<31;i++){
            if(answer &(1<<i)){
                count++;
            }
        }
        return count;
    }
};

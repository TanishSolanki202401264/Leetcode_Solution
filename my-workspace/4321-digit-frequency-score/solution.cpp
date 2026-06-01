class Solution {
public:
    int digitFrequencyScore(int n) {
        int lastdigit=0;
        int sum=0;
        while(n>0){
            lastdigit=n%10;
            n=n/10;
            sum=sum+lastdigit;
        }
        return sum;
    }
};

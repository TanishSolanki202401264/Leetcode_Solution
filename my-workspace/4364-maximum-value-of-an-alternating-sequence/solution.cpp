class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n==1){
            return s;
        }
        long long count=n/2;
        long long count1=count*m;
        long long count2=count-1;
        return s+count1-count2;
    }
};

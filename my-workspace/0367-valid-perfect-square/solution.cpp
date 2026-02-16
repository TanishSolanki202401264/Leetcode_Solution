class Solution {
public:
    bool isPerfectSquare(int num) {
        long long start=1;
        long long  end=num;
       long long  mid=start+(end-start)/2;
       while(start<=end){
        long long mid=start+(end-start)/2;
        long long  x=mid*mid;
        if(x==num){
            return 1;
        }
        else if(x<num){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
       }
       return 0;
    }
};

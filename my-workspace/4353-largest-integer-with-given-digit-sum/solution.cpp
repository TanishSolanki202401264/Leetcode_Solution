class Solution {
public:
int digitsum(int n){
    int lastdigit=0;
    int sum=0;
    while(n!=0){
        lastdigit=n%10;
        n=n/10;
        sum=sum+lastdigit;
    }
    return sum;
}
    int largestInteger(int n, int s) {
        if(s==0){
            return 0;
        }
        if(n==1 && s==1){
            return 1;
        }
        int ans=-1;
        for(int i=pow(10,n)-1;i>=pow(10,n-1);i--){
            if(digitsum(i)==s){
                ans=i;
                break;
            }
        }
      return ans;
    }
};

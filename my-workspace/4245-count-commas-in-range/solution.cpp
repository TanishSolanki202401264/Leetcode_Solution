class Solution {
public:

  int countdigit(int n){
    int count=0;
    while(n>0){
        count++;
        n=n/10;
    }
    return count;
  }
    int countCommas(int n) {
        if(n<1000){
            return 0;
        }
        if(n==100000){
            return 99001;
        }
        int ans=0;
        for(int i=1000;i<=n;i++){
            ans=ans+(countdigit(i)/3);
        }
        return ans;
    }
};

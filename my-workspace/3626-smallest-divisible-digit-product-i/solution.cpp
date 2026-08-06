class Solution {
public:
  int product(int n){
    int product=1;
    while(n!=0){
    int lastdigit=n%10;
    n=n/10;
    product=product*lastdigit;}
    return product;
 
  }
    int smallestNumber(int n, int t) {
        int ans=0;
        for(int i=n;i<=n*t;i++){
            if(product(i)%t==0){
                ans=i;
                break;
            }
        }
        return ans;
    }
};

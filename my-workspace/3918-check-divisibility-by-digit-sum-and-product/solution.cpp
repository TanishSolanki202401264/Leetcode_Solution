class Solution {
public:
int digitsum(int n){
    int sum=0;
    while(n!=0){
    int lastdigit=n%10;
    n=n/10;
    sum=sum+lastdigit;
    }
    return sum;
}
int digitp(int n){
    int pr=1;
    while(n!=0){
     int lastdigit=n%10;
     n=n/10;
     pr=pr*lastdigit;
    }
    return pr;
}
    bool checkDivisibility(int n) {
        int x=digitsum(n)+digitp(n);
        if(n%x==0){
           return 1;
        }
        else{
            return 0;
        }
    }
};

class Solution {
public:
  long long gcd(long long a,long long b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
  }

    bool canMeasureWater(int x, int y, int target) {
       // it can also be done by DFS,BFS but here may simple observation can be able to work
        if((x+y)>=target && target%gcd(x,y)==0){
            return 1;
        }
        else{
            return 0;
        }
    }
};

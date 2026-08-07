class Solution {
public:
    vector<int> closestDivisors(int num) {
        auto findfactors=[](int n){
            for(int i=sqrt(n);i>=0;i--){
                if(n%i==0){
                    return vector<int>{i,n/i};
                }
            }
            return vector<int>{1,n};
        };

        vector<int>a=findfactors(num+1);
        vector<int>b=findfactors(num+2);

        if(abs(a[0]-a[1])<abs(b[0]-b[1])){
            return a;
        }
        else{
            return b;
        }
    }
};

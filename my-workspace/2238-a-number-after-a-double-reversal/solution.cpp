class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num%10==0 && num!=0){
            return 0;
        }
        else{
            return 1;
        }
    }
};

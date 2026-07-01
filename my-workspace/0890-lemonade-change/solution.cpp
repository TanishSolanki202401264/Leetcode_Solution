class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int count5=0;
        int count10=0;
       for(int x:bills){
           if(x==5){
            count5++;
           }

           else if(x==10){
            if(count5==0){
                return 0;
            }
            count5--;
            count10++;
           }
           else{
            if(count5>0 && count10>0){
                count5--;
                count10--;
            }
            else if(count5>=3){
                count5=count5-3;
            }
            else{
                return 0;
            }
           }
       }
       return 1;
    }
};

class Solution {
public:
    int minAddToMakeValid(string s) {
      // stack na case ma TC and SC ae banne O(N) thasti hati tene reduce kareva mate apde aa code ne without using stack pan karii j shakay chee atla mate j apde kahii shakay ke Open and count no use karta 
       int open=0;
       int count=0;
       int n=s.size();
       for(int i=0;i<n;i++){
         if(s[i]=='('){
            open++;
         }
         else{
           if(open>0){
            open--;
           }
           else{
            count++;
           }
         }
       }
       return open+count;
    }
};

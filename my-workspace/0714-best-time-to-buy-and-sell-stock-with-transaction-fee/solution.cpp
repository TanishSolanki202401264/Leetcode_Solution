class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) {
 int n=prices.size();
   long aheadbuy,aheadnotbuy,currbuy,currnotbuy;
   aheadbuy=aheadnotbuy=0;

for(int idx=n-1;idx>=0;idx--){
    
    
  currbuy= max(-prices[idx] +aheadnotbuy,aheadbuy);


    currnotbuy= max(prices[idx]-fee+aheadbuy,aheadnotbuy);
   
    
    aheadbuy=currbuy;
    aheadnotbuy=currnotbuy;
}
       return aheadbuy;
    }
};

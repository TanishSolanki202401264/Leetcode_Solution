class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());
        int x=prices.size();
        int y=discounts.size();
        int k=min(x,y);
        double ans=0.0;
        for(int i=0;i<k;i++){
            ans=ans+(double)prices[i]*(100-discounts[i])/100.0;
        }
            for(int i=k;i<(int)x;i++){
                ans=ans+prices[i];
            }
        return ans;
    }
};

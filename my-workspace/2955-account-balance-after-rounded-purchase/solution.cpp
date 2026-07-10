class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
         for(int i = 0; ; i++) {
            if(purchaseAmount + i <= 100 && (purchaseAmount + i) % 10 == 0)
                return 100 - (purchaseAmount + i);
            if(purchaseAmount - i >= 0 && (purchaseAmount - i) % 10 == 0)
                return 100 - (purchaseAmount - i);
        }
    }
};

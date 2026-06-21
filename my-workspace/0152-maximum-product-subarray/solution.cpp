class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int product=1;
        int maxi1=INT_MIN;
        int maxi2=INT_MIN;
        for(int i=0;i<n;i++){
            product=product*nums[i];
            maxi1=max(maxi1,product);
            if(product==0){
                product=1;
            }
        }
        int pr=1;
        for(int i=n-1;i>=0;i--){
            pr=pr*nums[i];
            maxi2=max(maxi2,pr);
            if(pr==0){
               pr=1;
            }
        }
        return max({maxi1,maxi2});
    }
};

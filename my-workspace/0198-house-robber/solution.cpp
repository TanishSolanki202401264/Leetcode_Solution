class Solution {
public:




    int rob(vector<int>& nums) {
        int n=nums.size();
        //aa curr,prev and prev2 valu logic will be the best because space optimize karine apee chee bahu vadhare padtii

      
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1){
                take=take+prev2;
        }
        int nottake=0+prev;

        int curri=max(take,nottake);
        prev2=prev;
        prev=curri;
    }
    return prev;}
};

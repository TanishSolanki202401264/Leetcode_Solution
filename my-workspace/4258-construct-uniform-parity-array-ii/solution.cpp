class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        //we know that odd number-even number=odd number
        int min=*min_element(nums1.begin(),nums1.end());
        int n=nums1.size();
        bool hasodd=0;
        bool haseven=0;
        for(int i=0;i<n;i++){
           if(nums1[i]%2==0){
             hasodd=1;
           }
           else{
            haseven=1;
           }
        }
        //!hasodd means ke jo badha j number ni parity ae even hoy to odd number na hovo joie and !haseven means ke jo badha j number ni parity odd hoy to tema koi even number na hovo joie
        if(!hasodd ||!haseven){
            return true;
        }
        else if(min%2==1){
            return true;
        }
        else{
            return 0;
        }
    }
};

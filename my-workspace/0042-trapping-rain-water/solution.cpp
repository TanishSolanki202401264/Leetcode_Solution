class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int water=0;
        int leftmax=0,rightmax=0,maxheight=height[0],index=0;
        //Max height building part
        for(int i=0;i<n;i++){
            if(maxheight<height[i]){
               maxheight=height[i];
               index=i;
            }
        }
        //Left Part
        for(int i=0;i<index;i++){
            if(leftmax>height[i]){
                water=water+(leftmax-height[i]);
            }
            else{
                leftmax=height[i];
            }
        }
        //Right Part
         for(int i=n-1;i>index;i--){
            if(rightmax>height[i]){
                water=water+(rightmax-height[i]);
            }
            else{
                rightmax=height[i];
            }
        }
        return water;
    }
};

class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>leftmax(n);
        vector<int>rightmax(n);

        leftmax[0]=INT_MIN;
        for(int i=1;i<n;i++){
            leftmax[i]=max(leftmax[i-1],nums[i-1]);
        }
//aa leftmax and right max vala concept ne khass dhyan ma rakhavano aa khub j useful rahse ak nazare jova javii to tenu dhyan rakhavanu rahse 
        rightmax[n-1]=INT_MIN;
        for(int i=n-2;i>=0;i--){
            rightmax[i]=max(rightmax[i+1],nums[i+1]);
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            if(i==0 || i==n-1 || nums[i]>leftmax[i] || nums[i]>rightmax[i]){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

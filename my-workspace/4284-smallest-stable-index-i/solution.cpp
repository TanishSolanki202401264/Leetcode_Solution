class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
     int n=nums.size();
        vector<int>ans1(n);
        vector<int>ans2(n);
     
        ans1[0]=nums[0];
        for(int i=1;i<n;i++){
            ans1[i]=max(ans1[i-1],nums[i]);
        }      

        ans2[n-1]=nums[n-1]; 

        for(int i=n-2;i>=0;i--){
            ans2[i]=min(ans2[i+1],nums[i]);
        }  
        int answer=-1;
        for(int i=0;i<n;i++){
           if(ans1[i]-ans2[i]<=k){
            answer=i;
            break;
           }
        }  
        return answer;  
    }
};

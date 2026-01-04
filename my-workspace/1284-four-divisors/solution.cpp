class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int x=nums[i];
            int count=0;
            int sum=0;
         for(int j=1;j*j<=x;j++){
            if(x%j==0){
              int j1=j;
              int j2=x/j;
              if(j1==j2){
                count=count+1;
                sum=sum+j1;
              }
              else{
                count=count+2;
                sum=sum+j1+j2;
              }
               if(count>4){
           break;
         }
            }
         }
        if(count==4){
            ans=ans+sum;
        }

         

        }
        return ans;
    }
};

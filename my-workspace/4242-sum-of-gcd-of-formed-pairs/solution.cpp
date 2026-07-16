class Solution {
public:
  long long gcd(long long a,long long b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
  }


    
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        vector<int>ans;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            ans.push_back(gcd(maxi,nums[i]));
        }

        sort(ans.begin(),ans.end());
      
        long long  count=0;
        int m=ans.size();
         for(int i=0;i<m/2;i++){
            count=count+gcd(ans[i],ans[n-i-1]);
            }
        //return gcd(ans[0],ans[ans.size()-1]);
        return count;
    }
};

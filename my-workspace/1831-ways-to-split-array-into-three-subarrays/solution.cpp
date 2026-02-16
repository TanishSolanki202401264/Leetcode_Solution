class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        //ama koi pan jo sum ne sathe j leto javano hoy to prefix sum no use karvo
        int n=nums.size();
        int mod=1e9+7;
        vector<int>prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+nums[i];
        }
      int count=0;
      int j=0;
      int k=0;
      for(int i=0;i<n-2;i++){
        while(j<=i || (j<n-1 && prefix[j]<2*prefix[i])){
        j++;}
      
       while(k<j ||(k<n-1 && 2*prefix[k]<=prefix[n-1]+prefix[i])){
        k++;
       }
       if(k>j){
        count=(count+(k-j))%mod;
       }  
      }
      return count;
    }
};

class Solution {
public:
long long gcd(long long a,long long b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
    int countBeautifulPairs(vector<int>& nums) {
        int n=nums.size();
        //coprime means ke je te number no gcd ae 1 thase 
       int count=0;
       for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
         int x= to_string(nums[i]).length();
            int y=nums[j]%10;
            int z=nums[i]/pow(10,x-1);
            if(gcd(y,z)==1){
                count++;
            }
        }
       }
       return count;
    }
};

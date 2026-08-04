class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int j=1;
        int ans=0;
        while(j<n){
            if(i==j){
                j++;
                continue;
            }
            if(nums[j]-nums[i]==k){
                ans++;
               
                //aa code ne lidhe apde kahii shakay ke duplicate element ne skip nahhi thase atle j apde jo duplicate element ne skip karva hoy to int x=nums[i] and int y=nums[j] vali approach no use karvo padse 
                 int x =nums[i];
                int y =nums[j];
                while (i <n&& nums[i]==x){
                    i++;}
                while (j < n&& nums[j]==y){
                    j++;}
            }
           else if(nums[j]-nums[i]>k){
                  i++;
           }
           else{
            j++;
           }
            }
        
        //aa case ma apde khali diff atle ke nums[j]-nums[i]==diff chee te equal to k mate j check kariye chhiye but in real apde <k or diff>k mate try karvanu rahse 
        return ans;
    }
};

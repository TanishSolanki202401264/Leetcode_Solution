
class Solution {
public:
    int Atmost(vector<int> &nums,int k){
        int ans=0,n=nums.size();
        int start=0,end=0,count=0;
        unordered_map<int,int> m;

        //now traverse the nums
        while(end<n){
            m[nums[end]]++;
            if(m[nums[end]]==1)count++;//new element come
            
            //if count is greater than k shrink the window
            while(count>k && start<=end){
                m[nums[start]]--;
                if(m[nums[start]]==0){
                    count--;
                }
                start++;
            }
            //if count<=k calculate the subarray that is end-start+1
            ans+=end-start+1;
            
            //increase window size
            end++;

        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        //we use mathematics here if we have to calculate exactly k can we do some math here
        //exactly k = Atmost(k)-Atmost(k-1);
        //Atmost(k)=Exactly(k)+Exactly(k-1);
        
        return Atmost(nums,k)-Atmost(nums,k-1);
        
    }
};

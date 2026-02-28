class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int total=0;
        //atleast(k)-atleast(k+1)

        unordered_map<int,int>freq;
        int start=0;
        int end=0;
        int n=nums.size();
        int count=0;
       //count different integer in this window
       while(end<n){
        freq[nums[end]]++;
        if(freq[nums[end]]==1){
            count++;
        }
        //increase the window size untill different integer count equal to k
        //Decrease the window size
        while(count==k){
            total=total+(n-end);
            freq[nums[start]]--;
            if(freq[nums[start]]==0){
                count--;
            }
            start++;
        }
        end++;
       }
       start=0;
       end=0;
       count=0;
       freq.clear();
       k++;
        while(end<n){
        freq[nums[end]]++;
        if(freq[nums[end]]==1){
            count++;
        }
        //increase the window size untill different integer count equal to k
        //Decrease the window size
        while(count==k){
            total=total-(n-end);
            freq[nums[start]]--;
            if(freq[nums[start]]==0){
                count--;
            }
            start++;
        }
        end++;
       }
       return total;
    }
};

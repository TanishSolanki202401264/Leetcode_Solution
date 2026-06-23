class Solution {
public:
   long long findHours(vector<int>& piles,int k){

        long long hours = 0;

        for(int pile : piles){
            hours += (pile + k - 1) / k;
        }

        return hours;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(),nums.end());
        int start=1;
        int end=*max_element(nums.begin(),nums.end());
     int ans=end;
        while(start<=end){
            int mid=start +(end-start)/2;
            long long hours = findHours(nums,mid);
            if(hours <=threshold){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

        return ans;
        
    }
};

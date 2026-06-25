class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=i;j<n;j++){
                if(nums[j]==target){
                      count++;
                                }
                 int length=j-i+1;
                 if(count>length/2){
                    ans++;
                 }               
            }
        }
        return ans;
        //O(n square time ma run thai cheee ak biji approach pan cheee ke apde darek sub array ma individual map vaprine target ni freq thrrought pan majority element find karii shakiye chiiye)
    }
};

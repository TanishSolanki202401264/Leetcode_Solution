class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int currSum=0;
        int count=0;
        for(int num:nums){
            currSum+=num;
            if(mp.find(currSum-goal)!=mp.end()){
                count+=mp[currSum-goal];
            }
            mp[currSum]++;
        }
        return count;
    }
};

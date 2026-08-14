class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
         int n=nums.size();
        vector<int>ans;
        vector<int>freq(n+1,0);
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        for(int i=0;i<freq.size();i++){
            if(freq[i]==2){
                ans.push_back(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        //jo greater than n/2 hoy to basic map no use karii laie to pan chale pan jyare greater than n/3 hoy to it.first and it.second no j use karvoo padse it is important
       unordered_map<int,int>mp;
       for(int x:nums){
        mp[x]++;
       }
       vector<int>ans;
       for(auto it:mp){
        if(it.second>n/3){
            ans.push_back(it.first);
        }
       }
       return ans;
    }
};

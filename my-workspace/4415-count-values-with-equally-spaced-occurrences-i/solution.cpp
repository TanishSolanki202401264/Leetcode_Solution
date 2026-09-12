class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int,vector<int>>m;
int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]].push_back(i);
        }
        int count=0;
        for(auto x:m){
            vector<int>arr=x.second;
            if(arr.size()==3){
                if(arr[1]-arr[0]==arr[2]-arr[1]){
                    count++;
                }
            }
        }
        return count;
    }
};

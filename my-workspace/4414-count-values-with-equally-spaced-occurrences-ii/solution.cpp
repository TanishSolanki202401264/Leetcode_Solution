class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>>m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]].push_back(i);
        }
        int count=0;
        for(auto &x:m){
            vector<int>arr=x.second;

            if(arr.size()<3){
                continue;
            }
            int y=arr[1]-arr[0];
            bool ok=1;
        for(int i=2;i<arr.size();i++){
            if(arr[i]-arr[i-1]!=y){
                ok=0;
                break;
            }
        }
            if(ok){
                count++;
            }         
        }
    return count;
    }
};

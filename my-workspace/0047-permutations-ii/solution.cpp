class Solution {
public:
   void permut(vector<int>&arr,vector<vector<int>>&ans,int index){
      if(arr.size()==index){
        ans.push_back(arr);
        return ;
      }
      vector<bool>used(21,0);
      for(int i=index;i<arr.size();i++){
        if(used[arr[i]+10]==0){
        swap(arr[i],arr[index]);
        permut(arr,ans,index+1);
        swap(arr[i],arr[index]);
        used[arr[i]+10]=1;
        }
      }
   }
      
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
      permut(nums,ans,0);
         return ans;
    }
};

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
      int m=grid.size();
      int n=grid[0].size();
      vector<int>arr;
      vector<int>ans;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr.push_back(grid[i][j]);
        }
      }
      k=k%arr.size();
      for(int i=arr.size()-k;i<arr.size();i++){
        ans.push_back(arr[i]);
      }
      for(int i=0;i<arr.size()-k;i++){
        ans.push_back(arr[i]);
      }
      for(int i=0;i<ans.size();i++){
        grid[i/n][i%n]=ans[i];
      }
     
      return grid;
    }
};

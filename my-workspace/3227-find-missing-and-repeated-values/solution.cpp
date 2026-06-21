class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
       vector<int>arr;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               arr.push_back(grid[i][j]);
            }
        }

        //have ak frequency vector laine aa array na badha element mate frequency6 ganvanii and starting ma missing=-1 and duplicate equal to -1;//
      int k=arr.size();
        vector<int> freq(k + 1, 0);
        for(int x : arr) {
            freq[x]++;
        }
        int duplicate = -1;
        int missing = -1;
        for(int i = 1; i <= k; i++) {
            if(freq[i] == 2)
                duplicate = i;
            if(freq[i] == 0)
                missing = i;
        }
        return {duplicate, missing};
    }
};

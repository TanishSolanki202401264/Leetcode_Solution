class Solution {
public:
     void solve(int idx, vector<int>& candidates,
               int target,
               vector<int>& curr,
               vector<vector<int>>& ans) {
                //sort karvathii j duplicate element ne remove kari shakashe saralatathii
  
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
            //aa condition khass dhyan ma rakhjo
           for(int i=idx;i<candidates.size();i++){
              if (i > idx &&
                candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;

            curr.push_back(candidates[i]);
            //ahiya element ak j vakhat lai shakay chee atla mate j idx+1 karvuu j padse 
            solve(i+1,candidates,
                  target-candidates[i],
                  curr, ans);
          curr.pop_back();
           }     
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
       vector<vector<int>>ans;
       vector<int>curr;
        solve(0,candidates,target,
              curr, ans);
          return ans;
    }
};

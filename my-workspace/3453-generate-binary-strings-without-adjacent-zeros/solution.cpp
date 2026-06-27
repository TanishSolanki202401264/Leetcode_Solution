class Solution {
public:
   void solve(int n,string curr,vector<string>&ans){
    if(curr.length()==n){
        ans.push_back(curr);
        return ;
    }
     //if 1 hoy to direct add kari dyo and jo 0 hoy to jovanu ke empty hoy to j te and pahela no 0 na hoy to j
      solve(n,curr+'1',ans);
     if(curr.empty() || curr.back()!='0'){
        solve(n,curr+'0',ans);
     }
   }
    vector<string> validStrings(int n) {
        vector<string>ans;
        solve(n,"",ans);
        return ans;
    }
};

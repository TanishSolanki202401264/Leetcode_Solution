class Solution {
public:
    int maxProduct(int n) {
        vector<int>ans;
        while(n>0){
            int lastdigit=n%10;
            n=n/10;
            ans.push_back(lastdigit);
        }
        sort(ans.begin(),ans.end());
        return 1LL*ans[ans.size()-1]*ans[ans.size()-2];
    }
};

class Solution {
public:
    bool checkString(string s) {
        vector<int>ans;
        for(int i=0;i<s.size();i++){
           ans.push_back(s[i]);
        }

        if(is_sorted(ans.begin(),ans.end())){
            return 1;
        }
        else{
            return 0;
        }
    }
};

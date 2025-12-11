class Solution {
public:
    string sortSentence(string s) {
        vector<string>ans(10);
        string temp;
        int index=0;
        int count=0;
        while(index<=s.size()){
            if(index==s.size()|| s[index]==' ' ){
                int pos=temp[temp.size()-1]-'0';
                temp.pop_back();
                ans[pos]=temp;
                count++;
                temp.clear();
            }  else {
                temp += s[index];
            }
            index++;
        }

        string result;
        for (int i = 1; i <= count; i++) {
            result += ans[i];
            result += ' ';
        }
        result.pop_back();
        return result;

        
    }
};

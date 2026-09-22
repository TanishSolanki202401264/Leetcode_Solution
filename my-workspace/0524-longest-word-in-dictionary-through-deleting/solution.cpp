class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
       int n=s.size();
     vector<vector<int>>next(n+1,vector<int>(26,-1));
     for(int i=n-1;i>=0;i--){
         next[i]=next[i+1];
         next[i][s[i]-'a']=i;
     }
     string ans="";
     
     for(string word:dictionary){
         int pos=0;
         bool ok=1;
         
         for(char c:word){
             if(pos>n-1 || next[pos][c-'a']==-1){
                 ok=0;
                 break;
             }
         
             pos=next[pos][c-'a']+1;
         
     }
     if(ok){
         if(word.size()>ans.size() || (word.size()==ans.size() && word<ans)){
             ans=word;
         }
     }
     }
     return ans;
    }
};

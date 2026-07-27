class Solution {
public:
  unordered_map<string,int> level;
    vector<vector<string>> ans;

    void dfs(string word,
             string beginWord,
             vector<string>& path)
    {
        if(word==beginWord)
        {
            vector<string> temp=path;
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            return;
        }

        int len=word.size();

        string original=word;

        for(int i=0;i<len;i++)
        {
            char old=word[i];

            for(char ch='a';ch<='z';ch++)
            {
                word[i]=ch;

                if(level.find(word)!=level.end() &&
                   level[word]==level[original]-1)
                {
                    path.push_back(word);

                    dfs(word,beginWord,path);

                    path.pop_back();
                }
            }

            word[i]=old;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
       if(!st.count(endWord)){
        return {};
       }
       queue<string>q;
       q.push(beginWord);
       level[beginWord]=0;
       st.erase(beginWord);
       while(!q.empty()){
        string word=q.front();
        q.pop();
        int steps=level[word];
        for(int i=0;i<word.size();i++){
            char old=word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(st.count(word)){
                    level[word]=steps+1;
                    q.push(word);
                    st.erase(word);
                }
            }
            word[i]=old;
        }
       }
       if(level.find(endWord)==level.end()){
        return {};
       }
       vector<string>path;
       path.push_back(endWord);
       dfs(endWord,beginWord,path);
       return ans;
    }
};

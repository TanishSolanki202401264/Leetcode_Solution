class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>st(wordList.begin(),wordList.end());
        if(st.find(endWord)==st.end()){
            return 0;
            //aa hamesha yaad rakhajo ke st.find(x)==st.end() means ke x ae st ma present nathii
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            string word=cur.first;
            int steps=cur.second;
            if(word==endWord){
                return steps;
            }
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};

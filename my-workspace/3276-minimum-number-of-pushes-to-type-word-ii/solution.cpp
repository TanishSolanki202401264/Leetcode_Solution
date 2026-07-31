class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++){
            freq[word[i]-'a']++;
        }
        sort(freq.begin(),freq.end());
        reverse(freq.begin(),freq.end());
        int cost=0;
        for(int i=0;i<26;i++){
            if(freq[i]==0){
                continue;
            }
            cost=cost+(freq[i]*(i/8 +1));
        }
        return cost;
    }
};

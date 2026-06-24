class Solution {
public:
    bool isAnagram(string s, string t) {
        //be string anagram chee teno arth thay ke aa banne string ma rahela character ni freq pan same j chee 
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for(char ch:s){
            freq1[ch-'a']++;
        }
        for(char ch:t){
            freq2[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]){
                return 0;
            }
        }
        return 1;
    }
};

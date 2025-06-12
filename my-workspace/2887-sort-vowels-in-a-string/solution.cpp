class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;

        // Step 1: Collect vowels
        for(char c : s) {
            if(isVowel(c)) vowels.push_back(c);
        }

        // Step 2: Sort vowels
        sort(vowels.begin(), vowels.end());

        // Step 3: Replace vowels in order
        int idx = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(isVowel(s[i])) {
                s[i] = vowels[idx++];
            }
        }

        return s;
    }

private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};


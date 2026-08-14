
        //But general case ma i single pointer thi remainder sequence na repeats properly handle nahi thay. kem ke remainder je chee te ahiya repeat thay chee atle j apanane malyo te answer sachoo j hashe tem na kahii shakay
      
    //nums sorted chhe, pan x % value repeat thatu hoy chhe, etle simple pointer approach badha cases ma safe nathi. Etle actual accepted approach frequency/count wali chhe.
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> freq(value,0);
        for (int x:nums) {
            x %=value;
            if (x < 0)
                x +=value;
            freq[x]++;
        }
        int x = 0;
        while (true) {
            int rem = x%value;
            if (freq[rem]==0)
                return x;
            freq[rem]--;
            x++;
        }
    }
};

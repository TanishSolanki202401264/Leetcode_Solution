class Solution {
public:
    bool isPalindrome(string s) {
        vector<int>arr;
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                arr.push_back(tolower(s[i]));
            }
        }
            //have array mate palindrome check karo
            int start=0;
            int end=arr.size()-1;
            while(start<=end){
                if(arr[start]!=arr[end]){
                    return 0;
                }
                else{
                    start++;
                    end--;
                }
            }
        return 1;
    }
};

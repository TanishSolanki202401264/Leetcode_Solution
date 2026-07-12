class Solution {
public:
      vector<int> zFunction(string s){
        int n = s.size();
        vector<int> z(n);
        int L = 0, R = 0;
        for(int i=1;i<n;i++){
            if(i<=R){
                z[i]=min(R-i+1,z[i-L]);
            }
            while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
                z[i]++;
            }
            if(i+z[i]-1>R){
                L=i;
                R=i+z[i]-1;
            }
        }
        return z;
    }
    int strStr(string haystack, string needle) {
           string s = needle + "$" + haystack;
        vector<int> z =zFunction(s);
        int ans=-1;
        int m = needle.size();
        for(int i=0;i<z.size();i++){
            if(z[i]==m){
               ans=i-m-1;
               break;
            }
        }
        return ans;
    }
};

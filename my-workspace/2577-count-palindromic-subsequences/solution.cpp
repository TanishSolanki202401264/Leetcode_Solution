class Solution {
public:
    int countPalindromes(string s) {
        const int MOD = 1e9+7;
        int n=s.size();
        vector<vector<vector<long long>>> pre(
            n,
            vector<vector<long long>>(10,vector<long long>(10,0)));
        vector<vector<vector<long long>>> suf(
            n,
            vector<vector<long long>>(10,vector<long long>(10,0)));
        vector<long long> cnt(10);
        fill(cnt.begin(),cnt.end(),0);
        for(int i=0;i<n;i++){
            if(i>0)
                pre[i]=pre[i-1];
            int d=s[i]-'0';
            for(int x=0;x<10;x++)
                pre[i][x][d]+=cnt[x];
            cnt[d]++;
        }
        fill(cnt.begin(),cnt.end(),0);
        for(int i=n-1;i>=0;i--){
            if(i<n-1)
                suf[i]=suf[i+1];
            int d=s[i]-'0';
            for(int x=0;x<10;x++)
                suf[i][d][x]+=cnt[x];
            cnt[d]++;
        }
        long long ans=0;
        for(int mid=2;mid<=n-3;mid++){
            for(int a=0;a<10;a++){
                for(int b=0;b<10;b++){
                    ans=(ans+
                    pre[mid-1][a][b]*
                    suf[mid+1][b][a])
                    %MOD;
                }
            }
        }
        return ans;
    }
};

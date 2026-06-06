class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        auto velunqari = make_pair(nums, s);
        int n = nums.size();
        long long negative= -1e18;
        vector<long long>arr(3,negative);
        if (s[0]=='1') {
            arr[2]=0;}
        else {
            arr[0] = 0;
        }
        for (int i =1;i<n;i++) {
            vector<long long>brr(3,negative);
            vector<int>v;
            if (s[i] =='1') {
                v.push_back(0);
                v.push_back(1);
            } else {
                v.push_back(-1);
            }

            for (int x = -1; x <=1; x++) {
                if (arr[x+1]==negative){
                    continue;
                }
                for (int y : v) {
                    long long z = arr[x + 1];

                    if (x ==1||y==0) {
                        z += nums[i-1];
                    }
                    brr[y+1] =max(brr[y+1],z);
                }
            }
            arr = brr;
        }
        long long ans = 0;
        for (int x =-1;x<=1;x++) {
            if (arr[x+1]==negative) {
                continue;
            }
            long long z =arr[x+1];

            if (x ==1) {
                z +=nums[n-1];
            }
            ans =max(ans,z);
        }
        return ans;
    }
};

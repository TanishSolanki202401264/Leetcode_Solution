class Solution {
public:
    int zigZagArrays(int n, int l, int r) {

        const int MOD = 1e9 + 7;

        int m = r - l + 1;

        vector<int> up(m), down(m);
        vector<int> prefUp(m), prefDown(m);
        vector<int> newUp(m), newDown(m);

        for(int b = 0; b < m; b++) {
            up[b] = b;
            down[b] = m - 1 - b;
        }

        for(int len = 3; len <= n; len++) {

            prefUp[0] = up[0];
            prefDown[0] = down[0];

            for(int i = 1; i < m; i++) {
                prefUp[i] = (prefUp[i-1] + up[i]) % MOD;
                prefDown[i] = (prefDown[i-1] + down[i]) % MOD;
            }

            for(int x = 0; x < m; x++) {

                newUp[x] = 0;
                newDown[x] = 0;

                if(x > 0)
                    newUp[x] = prefDown[x-1];

                if(x < m-1)
                    newDown[x] =
                        (prefUp[m-1] - prefUp[x] + MOD) % MOD;
            }

            swap(up, newUp);
            swap(down, newDown);
        }

        if(n == 2)
            return 1LL * m * (m - 1) % MOD;

        long long ans = 0;

        for(int i = 0; i < m; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return ans;
    }
};

class Solution {
public:
    static const int MOD = 1e9+7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(Matrix &A, Matrix &B) {
        int n = A.size();

        Matrix C(n, vector<long long>(n,0));

        for(int i=0;i<n;i++) {
            for(int k=0;k<n;k++) {
                if(A[i][k]==0) continue;

                for(int j=0;j<n;j++) {
                    C[i][j] =
                    (C[i][j] +
                    A[i][k]*B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base,long long p) {

        int n = base.size();

        Matrix res(n, vector<long long>(n,0));

        for(int i=0;i<n;i++)
            res[i][i]=1;

        while(p) {

            if(p&1)
                res = multiply(res,base);

            base = multiply(base,base);

            p >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {

        int m = r-l+1;

        int sz = 2*m;

        vector<long long> init(sz,0);

        for(int x=0;x<m;x++) {
            init[x] = x;
            init[m+x] = m-1-x;
        }

        if(n==2) {
            long long ans=0;
            for(auto x:init)
                ans=(ans+x)%MOD;
            return ans;
        }

        Matrix T(sz, vector<long long>(sz,0));

        for(int x=0;x<m;x++) {

            for(int y=0;y<x;y++)
                T[x][m+y]=1;

            for(int y=x+1;y<m;y++)
                T[m+x][y]=1;
        }

        Matrix P = power(T,n-2);

        vector<long long> ans(sz,0);

        for(int i=0;i<sz;i++) {
            for(int j=0;j<sz;j++) {
                ans[i] =
                (ans[i] +
                P[i][j]*init[j])%MOD;
            }
        }

        long long res=0;

        for(auto x:ans)
            res=(res+x)%MOD;

        return res;
    }
};

class Solution {
public:

    pair<long long,long long> dp[2][2][20][11][11];

    pair<long long,long long> solve(int idx,int flag,int zero,
                                    int prev2,int prev,string &str){

        if(idx == str.size()){
            return {1,0};
        }

        if(dp[flag][zero][idx][prev2][prev] != make_pair(-1LL,-1LL)){
            return dp[flag][zero][idx][prev2][prev];
        }

        int limit = (flag == 0) ? (str[idx] - '0') : 9;

        pair<long long,long long> ans = {0,0};

        for(int i = 0; i <= limit; i++){

            int newFlag = flag || (i < limit);

            if(zero && i == 0){

                auto it = solve(idx + 1,
                                newFlag,
                                1,
                                10,
                                10,
                                str);

                ans.first += it.first;
                ans.second += it.second;
            }
            else{

                int curr = 0;

                if(prev2 != 10 && prev != 10){
                    if(prev > max(prev2,i) ||
                       prev < min(prev2,i)){
                        curr = 1;
                    }
                }

                auto it = solve(idx + 1,
                                newFlag,
                                0,
                                prev,
                                i,
                                str);

                ans.first += it.first;
                ans.second += it.second + 1LL * curr * it.first;
            }
        }

        return dp[flag][zero][idx][prev2][prev] = ans;
    }

    long long f(long long x){

        if(x < 0) return 0;

        string s = to_string(x);

        for(int a=0;a<2;a++)
            for(int b=0;b<2;b++)
                for(int c=0;c<20;c++)
                    for(int d=0;d<11;d++)
                        for(int e=0;e<11;e++)
                            dp[a][b][c][d][e] = {-1,-1};

        return solve(0,0,1,10,10,s).second;
    }

    long long totalWaviness(long long num1, long long num2) {
        return f(num2) - f(num1 - 1);
    }
};

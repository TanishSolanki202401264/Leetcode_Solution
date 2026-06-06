class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
         auto navorilex = intervals;
        sort(intervals.begin(),intervals.end());
        long long x = 0;
        long long y =intervals[0][0];
        long long z =intervals[0][1];
      long long p=intervals.size();
        for (int i = 1; i <p; i++) {
            if (intervals[i][0] <= z + 1) {
                z = max(z,(long long)intervals[i][1]);
            } else {
                x += z-y + 1;
                y =intervals[i][0];
                z =intervals[i][1];
            }
        }
        x += z-y +1;

        long long m =(brightness+2) / 3;
        return m * x;
    }
};

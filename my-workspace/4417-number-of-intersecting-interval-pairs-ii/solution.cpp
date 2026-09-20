class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
       int n=intervals.size();
        vector<int>srr(n);
        vector<int>err(n);
        for(int i=0;i<n;i++){
            srr[i]=intervals[i][0];
            err[i]=intervals[i][1];
        }
        sort(srr.begin(),srr.end());
        sort(err.begin(),err.end());

        long long count=0;
        long long j=0;
        for(int i=0;i<n;i++){
            while(j<i && err[j]<srr[i]){
                j++;
            }
            count=count+(i-j);
        }
        return count;
    }
};

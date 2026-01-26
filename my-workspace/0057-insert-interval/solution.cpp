class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
          vector<vector<int>>ans;
          int i=0;
          int n=intervals.size();
          while(i<n && newInterval[0]>intervals[i][1]){
            //overlap thata na hot te sequences ne ans ma nakhii do jeni mate new Interval no starting time bija na ending time karta ochho hoy
            ans.push_back(intervals[i]);
            i++;
          }

          if(i==n){
            ans.push_back(newInterval);
            return ans;
          }

        //jyare new interval ni ending pela na starting thi moti hoy to
        while(i<n && newInterval[1]>=intervals[i][0]){
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
       //bhega karo te nakhoo
        ans.push_back(newInterval);
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }


        return ans;

    }
};

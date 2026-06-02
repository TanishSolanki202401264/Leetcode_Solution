class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
       /* int n=landStartTime.size();
        int m=landDuration.size();

        int mini=INT_MAX;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
   ans=ans+(landStartTime[i]+landDuration[i] +waterStartTime[j]+waterDuration[j]);
   mini=min(mini,ans);
            }
        }  aa code jo land and water vala banne event independent hoy tyare j use karvano rehse
        return ans;*/




        int n=landStartTime.size();
        int m=waterStartTime.size();

        int mini=INT_MAX;
        int ans1=0;
        int ans2=0;
        for(int i=0;i<n;i++){
   for(int j=0;j<m;j++){
    //pahela land bharay jay then water bharay chee te case
            int landcomplete=landStartTime[i]+landDuration[i];
            int waterstarted=max(landcomplete,waterStartTime[j]);
            int ans1=waterstarted+waterDuration[j];
            //pahela water bharay jay thyen land bharay

            int watercomplete=waterStartTime[j]+waterDuration[j];
            int landstarted=max(watercomplete,landStartTime[i]);
            int ans2=landstarted+landDuration[i];

            mini=min({mini,ans1,ans2});
         }
        }
       return mini;
    }
};

class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
    int x=(startTime[0]-'0')*10 +(startTime[1]-'0');
    int y=(startTime[3]-'0')*10 +(startTime[4]-'0');
    int z=(startTime[6]-'0')*10 +(startTime[7]-'0');

    int a=(endTime[0]-'0')*10 +(endTime[1]-'0');    
    int b=(endTime[3]-'0')*10 +(endTime[4]-'0');  
     int c=(endTime[6]-'0')*10 +(endTime[7]-'0');  

      int st=x*3600+y*60+z;
        int end=a*3600+b*60+c;

        return end-st;
    }
};

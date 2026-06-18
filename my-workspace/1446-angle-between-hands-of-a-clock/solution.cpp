class Solution {
public:
    double angleClock(int hour, int minutes) {
       //kalak vala kata mate kalak and minute banne ne dhyan ma levanii and minite mate only minit ne j 
       
       double hourangle=hour*30 +minutes*0.5;
       double minangle=minutes*6;
    double diff=abs(hourangle-minangle); 
    double mini=min(diff,360-diff);
    return mini;
    }
};

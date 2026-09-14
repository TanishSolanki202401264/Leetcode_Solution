class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x3=min(rec1[2],rec2[2])-max(rec1[0],rec2[0]);
        int y3=min(rec1[3],rec2[3])-max(rec1[1],rec2[1]);
       /* int x1=abs(rec1[2]-rec1[0]);
        int y1=abs(rec1[3]-rec1[1]);
        int x2=abs(rec2[2]-rec2[0]);
        int y2=abs(rec2[3]-rec2[1]);
        int x=x1*y1;
        int y=x2*y2;
        int z=x3*y3;
        if(x+y-z>0){
            return 1;
        }
        else{
            return 0;
        }*/
        if(x3>0 && y3>0){
            return 1;
        }
        else{
            return 0;
        }
    }
};

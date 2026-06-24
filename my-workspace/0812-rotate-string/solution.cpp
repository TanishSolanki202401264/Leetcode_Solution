class Solution {
public:
    bool rotateString(string s, string goal) {
        
        //ak ak character ne string ni pachhal mokali ne comparision karta jav sarakhii rite
        for(int i=0;i<s.size();i++){
            s=s.substr(1)+s[0];

            if(s==goal){
                return 1;
                break;
            }
        }
        return 0;
    }
};

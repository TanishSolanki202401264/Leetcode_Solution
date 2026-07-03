class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        //ahiya be event tyare j conflict karii shake jyare event 1 no ending time ae evenet 2 na staring time karta moto hoy ke equal hoy
       //and biji event no end ae pahelii event na start karta moto hoy ke equal hoy
        if(event1[1]>=event2[0]  && event2[1]>=event1[0]){
            return 1;
        }
        else{
            return 0;
        }


    }
};

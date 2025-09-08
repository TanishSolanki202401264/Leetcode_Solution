class Solution {
public:
    string addBinary(string a, string b) {
        int s=a.size()-1;
        int t=b.size()-1;
        int x=0;
        string add="";
        while(s>=0 ||t>=0||x>0){
            int add1=x;
            if(s>=0){
                add1=add1+a[s--]-'0';
            }
            if(t>=0){
                add1=add1+b[t--]-'0';
            }
            if(add1%2==0){
                add= "0"+add;
            }
            else{
                 add= "1"+add;  
            }
            x=add1/2;
        }
        return add;
    }
};

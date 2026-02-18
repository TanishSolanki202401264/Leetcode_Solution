class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string>st;
        for(int i=0;i<logs.size();i++){
                if(logs[i]!="../"  && logs[i]!="./"){
                    st.push(logs[i]);
                }
                else if(logs[i]=="../"){
                    if(!st.empty()){
                    st.pop();}
                }
                else{
                    continue;
                }
        }
        return st.size();
    }
};

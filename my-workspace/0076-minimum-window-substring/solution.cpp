class Solution {
public:
    string minWindow(string s, string t) {
        int  total=t.size();
        //char and count
        unordered_map<char,int>m;
        //characters need in string s
        for(int i=0;i<t.size();i++){
            m[t[i]]++;
        }
        int start=0;
        int end=0;
        int ans=INT_MAX;
        //min length of substring 
        int index=-1;
        //index is storing starting index of the array
        while(end<s.size()){
            m[s[end]]--;//decrease the count of the character
            if(m[s[end]]>=0){//if count is not negative
                total--; //decrease the total
            }
            //can we decrease the size of window
            while(!total && start<=end){
                //update the length of the substring
                if(ans>end-start+1){
                    ans=end-start+1;
                    index=start;
                }
                m[s[start]]++;//increase the count of the character
                if(m[s[start]]>0){//if the count is positive then 
                    total++;  //increaase the total;
                }
                start++;//move the start which will decrease the size
            }
            //increase the size of window
            end++;

        }
        if(index==-1){
            return "";
        }
        string str="";
        for(int i=index;i<index+ans;i++){
            str+=s[i];
        }
        return str;
         
    }
};

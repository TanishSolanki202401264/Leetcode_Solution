class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        //be vector laine compare karo isomorphic string atle s no koi characater ae t na koi ak j character sathe match thavo joie

        vector<int>m1(256,-1);
        vector<int>m2(256,-1);

        for(int i=0;i<s.size();i++){
            if(m1[s[i]]!=m2[t[i]]){
                return 0;
            }
            m1[s[i]]=i;
            m2[t[i]]=i;
        }
        return 1;
    }
};

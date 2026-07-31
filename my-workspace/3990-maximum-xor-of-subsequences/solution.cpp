class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        const int BITS=31;
        vector<int>basis(BITS+1,0);
        for(int x:nums){
            int num=x;
            for(int bit=BITS;bit>=0;bit--){
                if((num &(1<<bit))==0){
                    continue;
                }
                if(basis[bit]==0){
                    basis[bit]=num;
                    break;
                }
                num=num^basis[bit];
            }
        }
        int ans=0;
        for(int bit=BITS;bit>=0;bit--){
            if((ans^basis[bit])>ans){
                ans=ans^basis[bit];
            }
        }
        //ama precedence ma khaas dhyan rakhavanu rahse atle ke > ni precedence ae always ^ karta vadhare j hoy cheee te pakku j chee 
        return ans;
    }
};

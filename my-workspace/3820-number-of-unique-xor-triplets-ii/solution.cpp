class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<int>db1(3001,0);
        for(auto it:nums){
            for(auto itt:nums){
                db1[it^itt]=1;
            }
        }

        vector<int>tp1(3001,0);
        for(int i=0;i<db1.size();i++){
            if(db1[i]==1){
                for(auto it:nums){
                    tp1[(i^it)]=1;
                }
            }
        }
        int ans=0;
        for(auto it:tp1){
            if(it==1){
                ans++;
            }
        }
        return ans;
    }
};

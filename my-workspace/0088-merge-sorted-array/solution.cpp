/*class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>ans;
        while(m>0){
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]!=0){
                ans.push_back(nums1[i]);
            }
        }
        }
        while(n>0){
            for(int i=0;i<nums2.size();i++){
                if(nums2[i]!=0){
                    ans.push_back(nums2[i]);
                }
            }
        }
          sort(ans.begin(),ans.end());
          return ans;
    }
};*/

class Solution {
public:
    void merge(vector<int>& nums1, int m,
               vector<int>& nums2, int n) {
        vector<int> ans;
        for(int i =0;i<m;i++) {
            ans.push_back(nums1[i]);
        }
        for(int i =0;i<n;i++) {
            ans.push_back(nums2[i]);
        }
        sort(ans.begin(),ans.end());
        for(int i =0; i<m+n;i++) {
            nums1[i]=ans[i];
        }
    }
};

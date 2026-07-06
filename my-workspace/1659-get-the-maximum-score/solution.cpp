class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        long long i=0;
        long long j=0;
        long long  s1=0;
        long long s2=0;
        long long ans=0;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                s1=s1+nums1[i];
                i++;
            }
            else if(nums1[i]>nums2[j]){
                s2=s2+nums2[j];
                j++;
            }
            else{
                ans=ans+max(s1,s2);
                ans=ans+nums1[i];
                s1=0;
                s2=0;
                i++;
                j++;
            }
        }
        while(i<n){
            s1=s1+nums1[i];
            i++;
        }
        while(j<m){
            s2=s2+nums2[j];
            j++;
        }
        ans=ans+max(s1,s2);
        return ans%1000000007;
        //simple two pointer +greedy approach chee
    }
};

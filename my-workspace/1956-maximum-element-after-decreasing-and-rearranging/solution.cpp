class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        long long  n=arr.size();
        arr[0]=1;
        for(long long i=1;i<n;i++){
           arr[i]=min(arr[i],arr[i-1]+1);
        }
      return arr[n-1];
    }
};

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        //forward and backward valli approach ne dhyan ma j rakhavani forward prefix sum array and backward suffix sum array havee anfd ans=max element forward mathii levano and after one deletion element tenathii pan moto rahe avii try karvani TC=O(N) and SC=O(N) anathii optimal approach pan avee two state dp TC=O(N) and SC=O(1)
          int n=arr.size();

        vector<int> forward(n);
        vector<int> backward(n);
        forward[0]=arr[0];
        for(int i=1;i<n;i++)
            forward[i]=max(arr[i],forward[i-1]+arr[i]);
        backward[n-1]=arr[n-1];
     for(int i=n-2;i>=0;i--)
            backward[i]=max(arr[i],backward[i+1]+arr[i]);
        int ans=*max_element(forward.begin(),forward.end());
        for(int i=1;i<n-1;i++)
            ans=max(ans,forward[i-1]+backward[i+1]);
        return ans;
        
    }
};

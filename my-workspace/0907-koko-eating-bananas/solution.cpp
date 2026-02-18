class Solution {
public:

    int minEatingSpeed(vector<int>& piles, int h) {
       int start=0;
       int end=0;
       int mid,ans;
       int n=piles.size();
       long long sum=0;
       for(int i=0;i<n;i++){
        sum=sum+piles[i];
        end=max(end,piles[i]);       
     }
     start=sum/h;
     if(!start){
        start=1;
     }
     while(start<=end){
        int mid=(start+end)/2;
        //mid amount of banana consume karva j padse
        int total =0;
        for(int i=0;i<n;i++){
            total=total+piles[i]/mid;
            if(piles[i]%mid){
                total++;
            }
        }
        if(total>h){
          start=mid+1;
        }
        else{
            ans=mid;
            end=mid-1;
        }
     }
     return ans;
    }
};

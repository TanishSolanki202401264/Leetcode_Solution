class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
       int start=0;
        int end=0;
        int mid,ans;
        for(int i=0;i<n;i++){
            start=max(start,weights[i]);
            end=end+weights[i];
        }
        
        while(start<=end){
            int mid=start+(end-start)/2;
            int pages=0;
            int count=1;
            for(int i=0;i<n;i++){
                pages=pages+weights[i];
                if(pages>mid){
                    count++;
                    pages=weights[i];
                }
            }
            
            if(count<=days){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return  ans;
        
    }
};

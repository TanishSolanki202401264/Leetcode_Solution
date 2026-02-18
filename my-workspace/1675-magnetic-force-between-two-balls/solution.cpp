class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
                int n=position.size();
        int start=1;
        int end,mid,ans;
        sort(position.begin(),position.end());
        end=position[n-1]-position[0];
        while(start<=end){
            int mid=start+(end-start)/2;
              
              int count=1;
              //1 li gay ne hamesha gani j levani
              int pos=position[0];
              for(int i=0;i<n;i++){
                  if(pos+mid<=position[i]){
                      count++;
                      pos=position[i];
                  }
              }
              if(count<m){
                  end=mid-1;//right side java devanu
              }
              else{
                  ans=mid;
                  start=mid+1;//left side javanu
              }
        }
        return ans;
    }
};

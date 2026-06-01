class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        //vectors are based on zero based off indexing please remeber this
        sort(cost.begin(),cost.end());
        reverse(cost.begin(),cost.end());
        long long sum=0;
        for(int i=0;i<n;i++){
          if(i%3!=2){
            sum+=cost[i];
          }
        }
        return sum;
    }
};

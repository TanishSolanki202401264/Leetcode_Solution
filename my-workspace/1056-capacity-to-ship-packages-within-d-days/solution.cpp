class Solution {
public:

    int findDays(vector<int>& weights, int capacity){
        int days = 1;
        int load = 0;
        for(int weight : weights){
            if(load + weight > capacity){
                days++;
                load = weight;
            }
            else{
                load += weight;
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(),
                                 weights.end());
        int end = accumulate(weights.begin(),
                             weights.end(), 0);
        int ans = end;
        while(start<=end){
            int mid = start + (end-start)/2;
            int requiredDays =
                    findDays(weights,mid);
            if(requiredDays<=days){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};

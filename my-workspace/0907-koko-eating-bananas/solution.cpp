class Solution {
public:

    long long findHours(vector<int>& piles,int k){

        long long hours = 0;

        for(int pile : piles){
            hours += (pile + k - 1) / k;
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int start = 1;
        int end = *max_element(piles.begin(), piles.end());

        int ans = end;

        while(start <= end){

            int mid = start + (end - start)/2;

            long long hours = findHours(piles, mid);

            if(hours <= h){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

        return ans;
    }
};

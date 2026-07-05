class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
  //kth largest find karvu hoy to min heap and k th smallest find karvuu hoy to max heap no j use karvano rahse
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < k; i++){
            pq.push(nums[i]);
        }
        for(int i = k; i < nums.size(); i++){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};

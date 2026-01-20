class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      
     //sauthii pahela k th largest find karvo hoy to min heap and k th smallest find karvo hoy to max heap
     priority_queue<int,vector<int>,greater<int>>p;
     for(int i=0;i<k;i++){
   p.push(nums[i]);
     }
     //have k thii bakina mate jo queue na sauthii nana element karta moto koi element male to tene q ma insert kari do
     for(int i=k;i<nums.size();i++){
        if(nums[i]>p.top()){
            p.push(nums[i]);
            p.pop();
        }
     }
     return p.top();
    }
};

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int len=0;
        int start=0;
        int end=0;
        int n=nums.size();
    unordered_map<int,int>count;

       while(end<n){
   count[nums[end]]++;
     //have jo koi element ae greater than k thii vadhare vakhat avee to end ne pahela amnam rehva devanu then start na count ne ghatadavanu and start ne vadharvanu 
     while(count[nums[end]]>k){
      count[nums[start]]--;
      start++;
     }
     end++;
    len=max(len,end-start+1);
     
       }
  return len-1;
            }
};

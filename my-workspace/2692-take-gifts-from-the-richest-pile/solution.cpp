class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        //max heap no use karvo padse ahiya and easy chee jo aa method tame sarakhii rite samjo to
        priority_queue<long long>p;
        long long n=gifts.size();
        for(int i=0;i<n;i++){
            p.push((long long)gifts[i]);
        }

        while(k--){
            long long t=p.top();
            p.pop();
            p.push(sqrt(t));
        }
        long long ans=0;
        while(!p.empty()){
            ans=ans+p.top();
            p.pop();
        }
       return ans;
    }
};

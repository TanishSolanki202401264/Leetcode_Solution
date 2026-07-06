class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0)
            return false;
            //min heap no ahiya use karvama avel chee
        unordered_map<int,int> freq;
        priority_queue<
            int,
            vector<int>,
            greater<int>
        > pq;
        for(int x:hand){
            freq[x]++;
            pq.push(x);
        }
        while(!pq.empty()){
            int start = pq.top();
            pq.pop();
            if(freq[start]==0)
                continue;
            for(int i=0;i<groupSize;i++){
                if(freq[start+i]==0)
                    return false;
                freq[start+i]--;
            }
        }
        return true;
    }
};

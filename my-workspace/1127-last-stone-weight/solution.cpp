class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        //priority queue ni help lo and be maximum element ne max heap thii find karo jethii banne no abs difference laine tene queue ma push karii do then again this process jya sudhii last element na vadhee queue ma tya sudhii aa karo
        priority_queue<int>p;
        //laine badhaa element ne queue ma nakhii do
        for(int i=0;i<stones.size();i++){
            p.push(stones[i]);
        }
        while(p.size()>1){
            int weight=p.top();
            p.pop();
            weight=weight-p.top();
            p.pop();
            //jo athdava baad koi weight vadhe to tene nakho nahitar nahii am
            if(weight){
                p.push(weight);
            }
        }
        return p.empty()? 0 :p.top();
        //jo queue empty hoy to return zero otherwise p na top ne return karo
    }
};

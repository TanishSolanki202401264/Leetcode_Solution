class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q;
       int n=tickets.size();
       for(int i=0;i<n;i++){
           q.push(i);
       }
       int Time=0;
       while(tickets[k]!=0){
        //jya sudhii zero na thay tya sudhii ak ak ghatadta javanu 
        tickets[q.front()]--;
        if(tickets[q.front()]){
            q.push(q.front());
        }
        q.pop();
        //Time ak thi vadhe 
        Time++;
       }
       return Time;
    }
};

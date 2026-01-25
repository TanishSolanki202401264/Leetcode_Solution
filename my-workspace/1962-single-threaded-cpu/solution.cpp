class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int>ans;
        int n=tasks.size();
        for(int i=0;i<n;i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        long long  timer=0;
        int i=0;
        //put all the task into min heap whose enqueue time is less than timer
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        while(!p.empty() || i<n){
            if(p.empty() && timer < tasks[i][0]){
                timer = tasks[i][0];
            }
        while(i<n && timer>=tasks[i][0]){
            p.push({tasks[i][1],tasks[i][2]});
            i++;
        }
    
        //not empty
       auto[processTime,index]=p.top();
       p.pop();
       ans.push_back(index);
       timer=timer+processTime;
       //prevent unnessary time 
        }
        return ans;
    }
};

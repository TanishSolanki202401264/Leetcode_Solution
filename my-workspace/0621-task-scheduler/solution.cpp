class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
          //pahela badha ni freq ne store kari do
          vector<int>freq(26,0);
//count is highest freq
int count=0;
          for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
            count=max(count,freq[tasks[i]-'A']);
          } 

          int ans=((count-1)*(n+1));
          for(int i=0;i<26;i++){
            if(freq[i]==count){
                ans++;
            }
          }
          if(ans>tasks.size()){
            return ans;
          }
          else{
            return tasks.size();
          }
    }
};

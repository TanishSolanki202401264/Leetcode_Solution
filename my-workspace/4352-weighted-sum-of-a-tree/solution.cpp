class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n=parent.size();
        vector<vector<int>>c(n);

        for(int i=1;i<n;i++){
            c[parent[i]].push_back(i);
        }

        vector<int>d(n,0);
        queue<int>q;
        d[0]=1;
        q.push(0);

        int h=1;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int a:c[x]){
                d[a]=d[x]+1;
                h=max(h,d[a]);
                q.push(a);
            }
        }
        long long count=0;
        for(int i=0;i<n;i++){
            long long w=1LL*nums[i]*(h-d[i]+1);

            count=count+w;
        }
        return count;
    }
};

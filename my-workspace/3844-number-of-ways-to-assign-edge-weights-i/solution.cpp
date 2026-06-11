class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int mod = 1000000007;
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        queue<pair<int,int>> q;
        vector<int> vis(n + 1, 0);

        q.push({1, 0});
        vis[1] = 1;

        int d = 0;

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int node = it.first;
            int dist = it.second;

            d = max(d, dist);

            for(int x : adj[node]) {
                if(!vis[x]) {
                    vis[x] = 1;
                    q.push({x, dist + 1});
                }
            }
        }

        long long ans = 1;

        for(int i = 1; i < d; i++) {
            ans = (ans * 2) % mod;
        }

        return ans;
    }
};

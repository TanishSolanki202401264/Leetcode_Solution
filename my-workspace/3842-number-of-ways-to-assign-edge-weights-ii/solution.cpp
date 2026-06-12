class Solution {
public:
    int mod = 1000000007;
    int LOG = 17;
    vector<vector<int>> up;
    vector<int> depth;
    
    long long power(long long a, long long b) {
        long long ans = 1;
        
        while(b > 0) {
            if(b % 2 == 1) ans = (ans * a) % mod;
            a = (a * a) % mod;
            b /= 2;
        }
        
        return ans;
    }
    
    int lca(int a, int b) {
        if(depth[a] < depth[b]) swap(a, b);
        
        int diff = depth[a] - depth[b];
        
        for(int i = 0; i < LOG; i++) {
            if(diff & (1 << i)) {
                a = up[i][a];
            }
        }
        
        if(a == b) return a;
        
        for(int i = LOG - 1; i >= 0; i--) {
            if(up[i][a] != up[i][b]) {
                a = up[i][a];
                b = up[i][b];
            }
        }
        
        return up[0][a];
    }
    
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        LOG = 20;
        
        vector<vector<int>> adj(n + 1);
        
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        up.assign(LOG, vector<int>(n + 1, 0));
        depth.assign(n + 1, 0);
        
        queue<int> q;
        vector<int> vis(n + 1, 0);
        
        q.push(1);
        vis[1] = 1;
        up[0][1] = 1;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(int x : adj[node]) {
                if(!vis[x]) {
                    vis[x] = 1;
                    depth[x] = depth[node] + 1;
                    up[0][x] = node;
                    q.push(x);
                }
            }
        }
        
        for(int i = 1; i < LOG; i++) {
            for(int node = 1; node <= n; node++) {
                up[i][node] = up[i - 1][up[i - 1][node]];
            }
        }
        
        vector<int> ans;
        
        for(auto &q : queries) {
            int a = q[0];
            int b = q[1];
            
            int c = lca(a, b);
            int d = depth[a] + depth[b] - 2 * depth[c];
            
            if(d == 0) {
                ans.push_back(0);
            } else {
                ans.push_back(power(2, d - 1));
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    struct SegTree {
        int n;
        vector<int> tree;
        vector<int>* nums;

        SegTree(vector<int>& a) {
            nums = &a;
            n = a.size();
            tree.resize(4 * n);
            build(1, 0, n - 1);
        }

        int better(int x, int y) {
            if (x == -1) return y;
            if (y == -1) return x;
            if ((*nums)[x] >= (*nums)[y]) return x;
            return y;
        }

        void build(int node, int l, int r) {
            if (l == r) {
                tree[node] = l;
                return;
            }

            int mid = (l + r) / 2;
            build(2 * node, l, mid);
            build(2 * node + 1, mid + 1, r);

            tree[node] = better(tree[2 * node], tree[2 * node + 1]);
        }

        int query(int node, int l, int r, int ql, int qr) {
            if (qr < l || r < ql) return -1;
            if (ql <= l && r <= qr) return tree[node];

            int mid = (l + r) / 2;
            int left = query(2 * node, l, mid, ql, qr);
            int right = query(2 * node + 1, mid + 1, r, ql, qr);

            return better(left, right);
        }

        int query(int l, int r) {
            return query(1, 0, n - 1, l, r);
        }
    };

    struct Node {
        long long val;
        long long cnt;
        int mnIdx;
        int l1, l2, r1, r2;
        int mxIdx;

        bool operator<(const Node& other) const {
            return val < other.val;
        }
    };

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> left(n), right(n);
        stack<int> st;

        // previous strictly smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();

            if (st.empty()) left[i] = -1;
            else left[i] = st.top();

            st.push(i);
        }

        while (!st.empty()) st.pop();

        // next smaller or equal
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();

            if (st.empty()) right[i] = n;
            else right[i] = st.top();

            st.push(i);
        }

        SegTree seg(nums);
        priority_queue<Node> pq;

        auto pushState = [&](int mnIdx, int l1, int l2, int r1, int r2) {
            if (l1 > l2 || r1 > r2) return;

            int mxIdx = seg.query(l1, r2);

            long long val = 1LL * nums[mxIdx] - nums[mnIdx];

            long long cnt;

            if (mxIdx <= mnIdx) {
                cnt = 1LL * (min(l2, mxIdx) - l1 + 1) * (r2 - r1 + 1);
            } else {
                cnt = 1LL * (l2 - l1 + 1) * (r2 - max(r1, mxIdx) + 1);
            }

            if (cnt <= 0) return;

            pq.push({val, cnt, mnIdx, l1, l2, r1, r2, mxIdx});
        };

        for (int i = 0; i < n; i++) {
            int l = left[i] + 1;
            int r = right[i] - 1;

            pushState(i, l, i, i, r);
        }

        long long ans = 0;
        long long need = k;

        while (need > 0 && !pq.empty()) {
            Node cur = pq.top();
            pq.pop();

            long long take = min(need, cur.cnt);
            ans += take * cur.val;
            need -= take;

            int i = cur.mnIdx;
            int mx = cur.mxIdx;

            if (mx < i) {
                pushState(i, mx + 1, cur.l2, cur.r1, cur.r2);
            } 
            else if (mx > i) {
                pushState(i, cur.l1, cur.l2, cur.r1, mx - 1);
            }
        }

        return ans;
    }
};

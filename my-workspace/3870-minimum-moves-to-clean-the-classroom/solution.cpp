class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        vector<vector<int>> id(m, vector<int>(n, -1));
        int sr = -1, sc = -1;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }
        int target = (1 << cnt) - 1;
        struct State {
            int r, c, e, mask;
        };
        queue<State> q;
        vector<vector<vector<vector<bool>>>> vis(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << cnt, false)
                )
            )
        );
        q.push({sr, sc, energy, 0});
        vis[sr][sc][energy][0] = true;
        int dist = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, e, mask] = q.front();
                q.pop();
                if (mask == target)
                    return dist;
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;
                    if (classroom[nr][nc] == 'X')
                        continue;
                    if (e == 0)
                        continue;
                    int ne = e - 1;
                    int nmask = mask;
                    if (classroom[nr][nc] == 'L')
                        nmask |= (1 << id[nr][nc]);
                    if (classroom[nr][nc] == 'R')
                        ne = energy;
                    if (vis[nr][nc][ne][nmask])
                        continue;
                    vis[nr][nc][ne][nmask] = true;
                    q.push({nr, nc, ne, nmask});
                }
            }
            dist++;
        }
        return -1;
    }
};

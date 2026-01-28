class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int INF = 1e9;

        vector<vector<vector<int>>> dist(
            m, vector<vector<int>>(n, vector<int>(k + 1, INF))
        );

        vector<tuple<int,int,int>> cells;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cells.push_back({grid[i][j], i, j});

        sort(cells.begin(), cells.end());

        using State = tuple<int,int,int,int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        dist[0][0][0] = 0;
        pq.push({0, 0, 0, 0});

        vector<int> ptr(k + 1, 0);

        while(!pq.empty()) {
            auto [cost, x, y, used] = pq.top();
            pq.pop();

            if(cost != dist[x][y][used]) continue;

            if(x == m-1 && y == n-1) return cost;

            if(x + 1 < m) {
                int nc = cost + grid[x+1][y];
                if(nc < dist[x+1][y][used]) {
                    dist[x+1][y][used] = nc;
                    pq.push({nc, x+1, y, used});
                }
            }

            if(y + 1 < n) {
                int nc = cost + grid[x][y+1];
                if(nc < dist[x][y+1][used]) {
                    dist[x][y+1][used] = nc;
                    pq.push({nc, x, y+1, used});
                }
            }

            if(used < k) {
                while(ptr[used] < (int)cells.size()) {
                    auto [val, i, j] = cells[ptr[used]];

                    if(val > grid[x][y]) break;

                    if(cost < dist[i][j][used + 1]) {
                        dist[i][j][used + 1] = cost;
                        pq.push({cost, i, j, used + 1});
                    }

                    ptr[used]++;
                }
            }
        }

        return -1;
    }
};

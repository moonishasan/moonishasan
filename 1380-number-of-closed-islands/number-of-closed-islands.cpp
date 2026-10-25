class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int totalIslands = 0;
        queue<pair<int, int>> q;
        int dir[] = {-1, 0, 1, 0, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                    grid[i][j] = 1;
                    bool hitsBorder = (i == 0 || j == 0 || i == n - 1 || j == m - 1);
                    while (!q.empty()) {
                        int i_ = q.front().first;
                        int j_ = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int dI = i_ + dir[k];
                            int dJ = j_ + dir[k + 1];
                            if (dI >= 0 && dJ >= 0 && dI < n && dJ < m && grid[dI][dJ] == 0) {
                                if (dI == 0 || dI == n - 1 || dJ == 0 ||dJ == m - 1) {
                                    hitsBorder = true;
                                }
                                q.push({dI, dJ});
                                grid[dI][dJ] = 1;
                            }
                        }
                    }
                    if (!hitsBorder) {
                        totalIslands++;
                    }
                }
            }
        }
        return totalIslands;
    }
};
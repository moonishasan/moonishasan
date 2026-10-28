class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bitset<1024>>> dp(
            m, vector<bitset<1024>>(n)
        );

        dp[0][0][grid[0][0]] = 1;

        // First row
        for (int j = 1; j < n; j++) {
            for (int x = 0; x < 1024; x++) {
                if (dp[0][j - 1][x]) {
                    dp[0][j][x ^ grid[0][j]] = 1;
                }
            }
        }

        // First column
        for (int i = 1; i < m; i++) {
            for (int x = 0; x < 1024; x++) {
                if (dp[i - 1][0][x]) {
                    dp[i][0][x ^ grid[i][0]] = 1;
                }
            }
        }

        // Remaining cells
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                for (int x = 0; x < 1024; x++) {
                    if (dp[i - 1][j][x]) {
                        dp[i][j][x ^ grid[i][j]] = 1;
                    }

                    if (dp[i][j - 1][x]) {
                        dp[i][j][x ^ grid[i][j]] = 1;
                    }
                }
            }
        }

        // Find minimum possible XOR
        for (int x = 0; x < 1024; x++) {
            if (dp[m - 1][n - 1][x]) {
                return x;
            }
        }

        return 0;
    

        // int m = grid.size();
        // int n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int> (n, 0));
        // // dp[i][j] means min xor path from (0,0) to (i,j) 
        // dp[0][0] = grid[0][0];
        // // first row
        // for(int i = 1; i < n; i++){
        //     dp[0][i] = dp[0][i-1] ^ grid[0][i];
        // }
        // // first col
        // for(int i = 1; i < m; i++){
        //     dp[i][0] = dp[i-1][0] ^ grid[i][0];
        // }
        // for(int i = 1; i < m; i++){
        //     for(int j = 1; j < n; j++){
        //         dp[i][j] = min((dp[i-1][j] ^ grid[i][j]), (dp[i][j-1] ^ grid[i][j]));
        //     }
        // }
        // return dp[m-1][n-1];
    }
};
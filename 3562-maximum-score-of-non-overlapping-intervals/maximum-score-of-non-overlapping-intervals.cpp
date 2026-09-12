class Solution {
public:
    // Returns true if a is lexicographically smaller than b
    bool smaller(vector<int>& a, vector<int>& b) {
        return a < b;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // Store original index
        // [start, end, weight, original_index]
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        // Sort by ending time
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[1] < b[1];
            });

        // prev[i] = largest j < i such that
        // intervals[j][1] < intervals[i][0]
        vector<int> prev(n, -1);

        for (int i = 0; i < n; i++) {

            int lo = 0;
            int hi = i - 1;
            int ans = -1;

            while (lo <= hi) {

                int mid = lo + (hi - lo) / 2;

                if (intervals[mid][1] < intervals[i][0]) {
                    ans = mid;
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }

            prev[i] = ans;
        }

        // dp[k][i]
        // maximum score using at most k intervals
        // from 0...i
        vector<vector<pair<long long, vector<int>>>> dp(
            5,
            vector<pair<long long, vector<int>>>(n)
        );

        for (int k = 1; k <= 4; k++) {

            for (int i = 0; i < n; i++) {

                // Option 1: don't take interval i
                pair<long long, vector<int>> notTake;

                if (i == 0)
                    notTake = {0, {}};
                else
                    notTake = dp[k][i - 1];


                // Option 2: take interval i
                pair<long long, vector<int>> take;

                int j = prev[i];

                if (j == -1) {
                    take.first = intervals[i][2];
                    take.second = {intervals[i][3]};
                }
                else {
                    take.first = intervals[i][2] + dp[k - 1][j].first;
                    take.second = dp[k - 1][j].second;
                    take.second.push_back(intervals[i][3]);
                    sort(take.second.begin(), take.second.end());
                }

                // Choose better score
                if (take.first > notTake.first) {
                    dp[k][i] = take;
                }
                else if (take.first < notTake.first) {
                    dp[k][i] = notTake;
                }
                else {
                    // Same score -> lexicographically smaller indices
                    if (take.second < notTake.second)
                        dp[k][i] = take;
                    else
                        dp[k][i] = notTake;
                }
            }
        }

        return dp[4][n - 1].second;
    }
        // hints
        // Use Dynamic Programming.
        // Sort intervals by right boundary.
        // Let dp[r][i] denote the maximum score having picked r intervals from the prefix of intervals ending at index i.
        // dp[r][i] = max(dp[r][i - 1], intervals[i][2] + dp[r][j]) where j is the largest index such that intervals[j][1] < intervals[i][0].
        // Since intervals is sorted by right boundary, we can find index j using binary search.
    
};
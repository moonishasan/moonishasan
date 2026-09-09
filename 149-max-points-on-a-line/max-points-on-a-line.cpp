class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2){
            return n;
        }
        int ans = 0;
        for(int i = 0; i < n-1; i++){
            unordered_map<string, int> mpp;
            for (int j = i + 1; j < n; j++) {
                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];
                // Normalize the slope
                int g = gcd(abs(dy), abs(dx));
                dy /= g;
                dx /= g;
                // Keep the sign consistent
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }
                // Vertical line
                if(dx == 0){
                    dy = 1;
                }
                // Horizontal line
                if(dy == 0){
                    dx = 1;
                }
                string slope = to_string(dy) + "/" + to_string(dx);
                mpp[slope]++;
                ans = max(ans, mpp[slope] + 1);
            }
        }
        return ans;
    }
};
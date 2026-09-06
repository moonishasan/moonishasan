class Solution {
public:
    int numDistinct(string s, string t) {
        int n  = s.size();
        int m = t.size();
        vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long> (m+1, 0));
        // dp[i][j] -> Number of ways to form the first j characters of t using the first i characters of s.
        dp[0][0] = 1;
        for(int j = 1; j < m+1; j++){
            dp[0][j] = 0;
        }
        for(int i = 1; i < n+1; i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < m+1; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];  
                    // we have two choices
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};
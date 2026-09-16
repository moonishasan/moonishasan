class Solution {
public:
    const int mod = 1e9 + 7;
    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(n+1,vector<int> (k+2,0));
        vector<int> pref(k+2,0);
        dp[n][k]=1;
        for(int i=n-1;i>=0;i--){
            for(int cnt=k;cnt>=0;cnt--){
                int ans=dp[i+1][cnt];
                ans=(ans+pref[cnt+1])%mod;
                dp[i][cnt]=ans;
                pref[cnt+1]=(pref[cnt+1]+dp[i][cnt+1])%mod;
            }
        }
        return dp[0][0];
    }
};
class Solution {
public:
    unsigned long long MOD = 1e9 + 7;
    int distinctSubseqII(string s) {
        vector<unsigned long long>dp(s.size()+1); // this will store the total subset starting from empty
        unordered_map<char,int>mpp;
        dp[0] = 1; // cause empty string is also a subset;
        for(int i = 1 ; i <= s.size(); i++){
            dp[i] = (2LL * dp[i-1] + MOD) % MOD;
            if(mpp.find(s[i-1]) != mpp.end()){
                // if the current character already exist
                dp[i] -= dp[mpp[s[i-1]]-1];
                dp[i] = (dp[i] + MOD) % MOD;
            }
            mpp[s[i-1]] = i;
        }
        return (dp[s.size()]-1 + MOD) % MOD;
    }
};
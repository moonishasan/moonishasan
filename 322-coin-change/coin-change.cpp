class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, -1);  // dp[i] => min no. of coins to make amount i
        dp[0] = 0;
        for(int i = 1; i < amount+1; i++){
            for(int coin : coins){
                if(coin <= i && dp[i-coin] != -1){
                    if(dp[i] == -1){
                        dp[i] = dp[i-coin] + 1;
                    }
                    else{
                        dp[i] = min(dp[i], dp[i-coin] + 1);
                    }
                }
            }
        }
        return dp[amount] == -1 ? -1 : dp[amount];
    }
};
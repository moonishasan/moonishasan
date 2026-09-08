class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000){
            return 0;
        }
        long long ans = 0;
        // cause it gives 1 comma
        if(n >= 1000){
            long long end = min(n, 999999LL);
            ans += (end-1000+1)*1;
        }
        // 2 comma
        if(n >= 1e6){
            long long end = min(n, 999999999LL);
            ans += (end-1e6+1)*2;
        }
        // 3 comma
        if(n >= 1e9){
            long long end = min(n, 999999999999LL);
            ans += (end-1e9+1)*3;
        }
        // 4 comma
        if(n >= 1e12){
            long long end = min(n, 999999999999999LL);
            ans += (end-1e12+1)*4;
        }
        if(n == 1e15){
            return ans + 5;
        }
        return ans;
    }
};
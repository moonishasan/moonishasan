class Solution {
private:
    int countSetBits(int n){
        int count = 0;
        while(n != 0){
            if(n&1){
                count++;
            }
            n = n >> 1;
        }
        return count;
    }
    bool isPrime(int n){
        if(n == 1){
            return false;
        }
        for(int i = 2; i < n; i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i = left; i <= right; i++){
            int setBits = countSetBits(i);
            if(isPrime(setBits)){
                ans++;
            }
        }
        return ans;
    }
};
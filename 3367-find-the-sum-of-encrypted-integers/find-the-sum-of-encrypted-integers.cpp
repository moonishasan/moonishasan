class Solution {
public:
    int encrypt(int x){
        vector<int> digits;
        while(x){
            int d = x % 10;
            digits.push_back(d);
            x /= 10;
        }
        int maxi = 0;
        for(int d : digits){
            maxi = max(d, maxi);
        }
        int ans = 0;
        for(int i = 0; i < digits.size(); i++){
            ans = ans * 10 + maxi;
        }
        return ans;
    }
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        for(int n : nums){
            sum += encrypt(n);
        }
        return sum;
    }
};
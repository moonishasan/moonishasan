class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int maxi = INT_MIN;
        for(int n : nums){
            maxi = max(n, maxi);
        }
        for(int n : nums){
            ans += (maxi-n);
        }
        return ans;
    }
};
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int mid = n/2;
        for(int i = 0; i < n; i++){
            int diff = abs(nums[i] - nums[mid]);
            ans += diff;
        }
        return ans;
    }
};
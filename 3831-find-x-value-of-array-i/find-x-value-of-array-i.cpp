class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> cnt(k, 0); // subarrays ending at previous index, by product mod k
        for(int a : nums){
            vector<long long> newCnt(k, 0);
            for (int r = 0; r < k; r++) {
                if (cnt[r]) {
                    newCnt[(r * (a % k)) % k] += cnt[r];
                }
            }
            newCnt[a % k] += 1; // subarray starting at this element
            cnt = newCnt;
            for (int r = 0; r < k; r++) {
                result[r] += cnt[r];
            }
        }
        return result;
    }
};
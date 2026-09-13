class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> freq;
        for(int n : nums){
            freq[n]++;
        }
        for(auto it : freq){
            if(it.second == 2){
                ans ^= it.first;
            }
        }
        return ans;
    }
};
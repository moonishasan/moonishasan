class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int n : nums){
            freq[n]++;
        }
        for(int n : nums){
            if(freq[n] == 1 && n % 2 == 0){
                return n;
            }
        }
        return -1;
    }
};
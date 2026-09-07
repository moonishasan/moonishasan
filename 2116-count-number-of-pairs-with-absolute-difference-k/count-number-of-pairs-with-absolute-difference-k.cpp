class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int count = 0;
        for(int n : nums){
            count += freq[n-k];
            count += freq[n+k];
            freq[n]++;
        }
        return count;


        // int count = 0;
        // for(int i = 0; i < nums.size()-1; i++){
        //     for(int j = i+1; j < nums.size(); j++){
        //         if(abs(nums[i]- nums[j]) == k){
        //             count++;
        //         }
        //     }
        // }
        // return count;
    }
};
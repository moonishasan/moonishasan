class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int count = 0;
        int i = 0;
        while(i < nums.size()-1){
            int j = i+1;
            while(j < nums.size()){
                if(nums[i] + nums[j] < target){
                    count++;
                }
                j++;
            }
            i++;
        }
        return count;
    }
};
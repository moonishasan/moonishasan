class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return backtrack(nums, 0, 0);
    }
private:
    int backtrack(vector<int>& nums, int index, int currXor){
        if(index == nums.size()){
            return currXor;
        }
        int include = backtrack(nums, index+1, currXor ^ nums[index]);
        int exclude = backtrack(nums, index+1, currXor);
        return include + exclude;
    }
};
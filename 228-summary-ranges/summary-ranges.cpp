class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0){
            return {};
        }
        vector<string> ans;
        vector<int> range;
        range.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == 1 + nums[i-1] && i != nums.size()-1){
                continue;
            }
            if(nums[i] == 1 + nums[i-1] && i == nums.size()-1){
                if(range[0] != nums[i]){
                    ans.push_back(to_string(range[0]) + "->" + to_string(nums[i]));
                    range.pop_back();
                }
            }
            else if(nums[i] != 1 + nums[i-1]){
                if(range[0] == nums[i-1]){
                    ans.push_back(to_string(range[0]));
                    range.pop_back();
                }
                else if(range[0] != nums[i-1]){
                    ans.push_back(to_string(range[0]) + "->" + to_string(nums[i-1]));
                    range.pop_back();
                }
                range.push_back(nums[i]);
            }
        }
        if(range.size() == 1){
            ans.push_back(to_string(range[0]));
        }
        return ans;
    }
};
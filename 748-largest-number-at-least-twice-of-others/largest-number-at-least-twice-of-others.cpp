class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        priority_queue<int> pq(nums.begin(), nums.end());
        int largest = pq.top();
        int top_indx = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == largest){
                top_indx = i;
            }
        }
        pq.pop();
        int sec_largest = pq.top();
        if(largest >= 2 * sec_largest){
            return top_indx;
        }
        return -1;
    }
};
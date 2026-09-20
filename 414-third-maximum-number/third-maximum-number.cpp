class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        priority_queue<int> pq(s.begin(), s.end());
        if(s.size() < 3){
            return pq.top();
        }
        int top;
        for(int i = 0; i < 3; i++){
            top = pq.top();
            pq.pop();
        }
        return top;
    }
};
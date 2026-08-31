class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int num : nums){
            s.insert(num);
        }
        int longest = 0;
        for(int num : s){
            if(s.find(num-1) == s.end()){
                int currNum = num;
                int currLength = 1;
                while(s.find(currNum+1) != s.end()){
                    currNum++;
                    currLength++;
                }
                longest = max(longest, currLength);
            }
        }
        return longest;
    }
};
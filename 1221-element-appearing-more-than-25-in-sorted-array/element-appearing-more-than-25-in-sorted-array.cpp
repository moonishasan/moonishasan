class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(auto i : arr){
            freq[i]++;
        }
        int maxFreq = 0;
        for(auto it : freq){
            maxFreq = max(maxFreq, it.second);
        }
        for(auto it : freq){
            if(it.second == maxFreq){
                return it.first;
            }
        }
        return -1;
    }
};
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();

        for(int i = 0; i + n/4 < n; i++) {
            if(arr[i] == arr[i + n/4]) {
                return arr[i];
            }
        }

        return -1;

        // unordered_map<int, int> freq;
        // for(auto i : arr){
        //     freq[i]++;
        // }
        // int maxFreq = 0;
        // for(auto it : freq){
        //     maxFreq = max(maxFreq, it.second);
        // }
        // for(auto it : freq){
        //     if(it.second == maxFreq){
        //         return it.first;
        //     }
        // }
        // return -1;
    }
};
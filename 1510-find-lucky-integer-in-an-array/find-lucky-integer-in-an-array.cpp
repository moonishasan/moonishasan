class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        vector<int> luckies;
        for(int n : arr){
            freq[n]++;
        }
        for(int n : arr){
            if(n == freq[n]){
                luckies.push_back(n);
            }
        }
        int maxi = -1;
        for(int n : luckies){
            maxi = max(maxi, n);
        }
        return maxi;
    }
};
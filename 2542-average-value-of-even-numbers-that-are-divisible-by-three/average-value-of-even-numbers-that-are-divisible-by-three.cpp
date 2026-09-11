class Solution {
public:
    int averageValue(vector<int>& nums) {
        vector<int> reqNum;
        for(int n : nums){
            if(n % 2 == 0 && n % 3 == 0){
                reqNum.push_back(n);
            }
        }
        int sum = 0;
        for(int n : reqNum){
            sum += n;
        }
        if(reqNum.size() == 0){
            return 0;
        }
        int avg = sum / reqNum.size();
        return avg;
    }
};
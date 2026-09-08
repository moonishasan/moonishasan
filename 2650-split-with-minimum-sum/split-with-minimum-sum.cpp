class Solution {
public:
    int splitNum(int num) {
        vector<int> digits;
        while(num){
            int dig = num % 10;
            digits.push_back(dig);
            num /= 10;
        }
        int ans = 0;
        sort(digits.begin(), digits.end());
        int num1 = 0;
        int num2 = 0;
        for(int i = 0; i < digits.size(); i+=2){
            num1 = num1*10 + digits[i];
            if(i + 1 < digits.size()){
                num2 = num2*10 + digits[i+1];
            }
        }
        return num1 + num2;
    }
};
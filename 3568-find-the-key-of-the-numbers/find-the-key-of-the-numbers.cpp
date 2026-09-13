class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int ans = 0;
        int place = 1;
        for(int i = 0; i < 4; i++){
            int dig1 = num1 % 10;
            int dig2 = num2 % 10;
            int dig3 = num3 % 10;
            ans += min(min(dig1, dig2), dig3) * place;
            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
            place *= 10;
        }
        return ans;
    }
};
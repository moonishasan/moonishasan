class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int count = 0;
        string _num = to_string(num);
        for(int i = 0; i <= _num.size()-k; i++){
            int divisor = 0;
            int temp = k;
            int idx = i;
            while(temp != 0){
                divisor = divisor * 10 + (_num[idx]-'0');
                idx++;
                temp--;
            }
            if(divisor != 0 && num % divisor == 0){
                count++;
            }
        }
        return count;
    }
};
class Solution {
public:
    int pivotInteger(int n) {
        for(int i = 1; i <= n; i++){
            int x = i;
            int sum1 = 0;
            int sum2 = 0;
            for(int j = 1; j <= x; j++){
                sum1 += j;
            }
            for(int j = x; j <= n; j++){
                sum2 += j;
            }
            if(sum1 == sum2){
                return i;
            }
        }
        return -1;
    }
};
class Solution {
public:
    int no_of_set_bits(int n){
        int count = 0;
        while(n != 0){
            if(n & 1){
                count++;
            }
            n >>= 1;
        }
        return count;
    }  
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b){
            if(no_of_set_bits(a) != no_of_set_bits(b)){
                return no_of_set_bits(a) < no_of_set_bits(b);
            }
            return a < b;
        });
        return arr;
    }
};
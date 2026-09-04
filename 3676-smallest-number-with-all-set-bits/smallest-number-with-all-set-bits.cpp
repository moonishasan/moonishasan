class Solution {
public:
    int smallestNumber(int n) {
        for(int i = n; i <= 2*n; i++){
            int temp = i;
            while(temp != 0){
                if(temp&1){
                    temp = temp >> 1;
                }
                else{
                    break;
                }
            }
            if(temp == 0){
                return i;
            }        
        }
        return -1;
    }
};
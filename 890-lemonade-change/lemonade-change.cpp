class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        for(int bill : bills){
            if(bill == 5){
                five++;
            }
            else if(bill == 10){
                if(five == 0){
                    return false;
                }
                else if(five > 0){
                    five--;
                    ten++;
                } 
            }
            else{
                if(five >= 1 && ten >= 1){
                    five--;
                    ten--;
                }
                else if(five >= 3){
                    five -= 3;
                }
                else if(five < 1){
                    return false;
                }
                else if(ten < 1){
                    return false;
                }
            }
        }
        return true;
    }
};
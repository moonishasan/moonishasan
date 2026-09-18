class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ans(2, 0);
        int mini = INT_MAX;   // 
        for(int i = 1; i * i <= area; i++){
            if(area % i == 0){
                if(mini > abs(i - (area/i))
                ){
                    ans[0] = area/i;
                    ans[1] = i;
                    mini = abs(i - (area/i));
                }
            }
        }
        return ans;
    }
};
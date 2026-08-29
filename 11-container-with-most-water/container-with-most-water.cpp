class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int st = 0;
        int end = n-1;
        int maxArea = 0;
        while(st < end){
            int width = end - st;
            int currArea = width * min(height[st], height[end]);
            maxArea = max(currArea, maxArea);
            if(height[st] < height[end]){
                st++;
            }
            else{
                end--;
            }
        }
        return maxArea;
    }
};
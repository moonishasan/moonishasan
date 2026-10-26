class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int totalIslands = 0;
        queue<pair<int,int>>q;
        int rows = grid.size();
        int cols = grid[0].size();
        int dir[] = {-1,0,1,0,-1};
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                long long totalSum = 0;
                if(grid[row][col] > 0){
                    totalSum += grid[row][col];
                    grid[row][col] = 0;
                    q.push({row,col});
                    while(!q.empty()){
                        int currRow = q.front().first;
                        int currCol = q.front().second;
                        q.pop();
                        for(int k = 0; k < 4; k++){
                            int delRow = currRow + dir[k];
                            int delCol = currCol + dir[k+1];
                            if(delRow >= 0 && delCol >= 0 && delRow < rows && delCol < cols && grid[delRow][delCol] > 0){
                                totalSum += grid[delRow][delCol];
                                grid[delRow][delCol] = 0;
                                q.push({delRow,delCol});
                            }
                        }
                    }
                    if(totalSum != 0 && totalSum % k == 0){
                        totalIslands++;
                    }
                }
            }
        }
        return totalIslands;
    }
};
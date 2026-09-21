class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Sets for rows, columns and 3x3 boxes
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                // Ignore empty cells
                if(board[i][j] == '.') {
                    continue;
                }
                char digit = board[i][j];

                // Find which 3x3 box this cell belongs to
                int boxIndex = (i / 3) * 3 + (j / 3);

                // If digit already exists in row, column or box
                if(rows[i].count(digit) ||
                   cols[j].count(digit) ||
                   boxes[boxIndex].count(digit)) {
                    return false;
                }
                // Add digit to row, column and box
                rows[i].insert(digit);
                cols[j].insert(digit);
                boxes[boxIndex].insert(digit);
            }
        }   
        return true;
    }    
};
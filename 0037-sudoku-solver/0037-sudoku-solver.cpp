#include <vector>
using namespace std;

class Solution {
private:
    // Check if placing num at board[row][col] is valid
    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; i++) {
            // Check row
            if (board[row][i] == num) return false;
            // Check column
            if (board[i][col] == num) return false;
            // Check 3x3 subgrid
            if (board[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] == num) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                // Find an empty cell
                if (board[row][col] == '.') {
                    // Try placing each number (1-9)
                    for (char num = '1'; num <= '9'; num++) {
                        if (isValid(board, row, col, num)) {
                            board[row][col] = num; // Place num
                            // Recursively try to solve the rest of the board
                            if (solve(board)) return true;
                            board[row][col] = '.'; // Reset cell if not solvable
                        }
                    }
                    return false; // No valid number found, trigger backtracking
                }
            }
        }
        return true; // Board is completely solved
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

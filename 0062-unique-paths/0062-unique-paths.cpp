class Solution {
private:
    int solvememo(int m, int n, int i, int j, vector<vector<int>>& memo) {
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        if (i >= m || j >= n) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int rightmove = solvememo(m, n, i, j + 1, memo);
        int downmove = solvememo(m, n, i + 1, j, memo);
        memo[i][j] = rightmove + downmove;
        return memo[i][j];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return solvememo(m, n, 0, 0, memo);
    }
};

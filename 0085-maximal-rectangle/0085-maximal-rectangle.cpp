class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<int> heights(cols, 0); // Heights of rectangles ending at each cell for each column
        int maxArea = 0;
        
        for (int i = 0; i < rows; ++i) {
            // Update heights for each column
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0; // Reset to 0 if encountered '0'
                }
            }
            
            // Compute maximal rectangle area using histogram approach for each row
            stack<int> stk;
            for (int j = 0; j <= cols; ++j) {
                while (!stk.empty() && (j == cols || heights[j] < heights[stk.top()])) {
                    int h = heights[stk.top()];
                    stk.pop();
                    int w = stk.empty() ? j : j - stk.top() - 1;
                    maxArea = max(maxArea, h * w);
                }
                stk.push(j);
            }
        }
        
        return maxArea;
    }
};

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Stack to store the indices of bars in non-decreasing order of height
        stack<int> st;
        
        int maxArea = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; ++i) {
            // Push the current index onto the stack if either stack is empty or current height is greater than or equal to the height of bar at index on top of the stack
            while (!st.empty() && (i == n || heights[i] < heights[st.top()])) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            // Push the current index onto the stack
            st.push(i);
        }
        
        return maxArea;
    }
};

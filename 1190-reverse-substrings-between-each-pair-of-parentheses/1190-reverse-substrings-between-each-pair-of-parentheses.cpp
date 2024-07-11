#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string current;
        
        for (char c : s) {
            if (c == '(') {
                // Push the current string to stack and start a new one
                st.push(current);
                current = "";
            } else if (c == ')') {
                // Reverse the current string and append it to the top of the stack
                reverse(current.begin(), current.end());
                current = st.top() + current;
                st.pop();
            } else {
                // Append character to current string
                current += c;
            }
        }
        
        return current;
    }
};

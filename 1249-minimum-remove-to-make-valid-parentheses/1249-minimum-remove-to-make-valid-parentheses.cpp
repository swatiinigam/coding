#include <string>
#include <stack>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        unordered_set<int> indexesToRemove;
        
        // First pass: identify invalid parentheses
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    indexesToRemove.insert(i);
                }
            }
        }
        
        // Remaining indexes in stack are unmatched opening parentheses
        while (!st.empty()) {
            indexesToRemove.insert(st.top());
            st.pop();
        }
        
        // Build the resulting string
        string result;
        for (int i = 0; i < s.size(); ++i) {
            if (indexesToRemove.find(i) == indexesToRemove.end()) {
                result += s[i];
            }
        }
        
        return result;
    }
};

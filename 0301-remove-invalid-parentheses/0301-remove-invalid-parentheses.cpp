#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        if (s.empty()) return {""};

        unordered_set<string> visited;
        queue<string> q;
        bool found = false;

        q.push(s);
        visited.insert(s);

        while (!q.empty()) {
            int size = q.size();
            unordered_set<string> level_visited;

            for (int i = 0; i < size; ++i) {
                string curr = q.front();
                q.pop();

                if (isValid(curr)) {
                    result.push_back(curr);
                    found = true;
                }

                if (found) continue;

                for (int j = 0; j < curr.size(); ++j) {
                    if (curr[j] != '(' && curr[j] != ')') continue;

                    string next = curr.substr(0, j) + curr.substr(j + 1);
                    if (visited.find(next) == visited.end()) {
                        level_visited.insert(next);
                    }
                }
            }

            if (found) break;

            for (const string& str : level_visited) {
                q.push(str);
                visited.insert(str);
            }
        }

        return result;
    }

private:
    bool isValid(const string& s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') {
                ++balance;
            } else if (c == ')') {
                --balance;
            }

            if (balance < 0) return false;
        }
        return balance == 0;
    }
};

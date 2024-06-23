class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        unordered_map<char, int> countT;
        for (char c : t) {
            countT[c]++;
        }

        unordered_map<char, int> window;
        int have = 0, need = countT.size();
        int left = 0, right = 0;
        int minLen = INT_MAX, minLeft = 0;

        while (right < s.size()) {
            char c = s[right];
            window[c]++;
            if (countT.find(c) != countT.end() && window[c] == countT[c]) {
                have++;
            }

            while (have == need) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }

                window[s[left]]--;
                if (countT.find(s[left]) != countT.end() && window[s[left]] < countT[s[left]]) {
                    have--;
                }
                left++;
            }
            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};
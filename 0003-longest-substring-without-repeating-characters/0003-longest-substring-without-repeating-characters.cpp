#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int n = s.size();
        int maxlen = 0;
        unordered_map<char, int> charcount;

        while (j < n) {
            charcount[s[j]]++;

            // If there are duplicate characters, move the start of the window
            while (charcount[s[j]] > 1) {
                charcount[s[i]]--;
                if (charcount[s[i]] == 0) {
                    charcount.erase(s[i]);
                }
                i++;
            }

            // Calculate the length of the current window
            maxlen = max(maxlen, j - i + 1);
            j++;
        }

        return maxlen;
    }
};

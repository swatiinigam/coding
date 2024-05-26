#include <string>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        // Count frequency of each character
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Max-heap to store characters by frequency
        priority_queue<pair<int, char>> maxHeap;
        for (auto& entry : freq) {
            maxHeap.push({entry.second, entry.first});
        }

        // Previous character (initially empty)
        pair<int, char> prev = {0, '#'};

        // Result string
        string result;

        // Process the heap
        while (!maxHeap.empty()) {
            auto current = maxHeap.top();
            maxHeap.pop();

            // Append the current character to the result
            result += current.second;

            // Decrease the frequency of the current character
            current.first--;

            // If there was a previously used character, push it back into the heap
            if (prev.first > 0) {
                maxHeap.push(prev);
            }

            // Update previous character to the current character
            prev = current;
        }

        // Check if the reorganization was successful
        if (result.size() != s.size()) {
            return "";
        }

        return result;
    }
};

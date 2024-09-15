class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Convert the word list to a set for quick lookup
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        // If endWord is not in the word list, return 0
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        // Use a queue for BFS; it stores pairs of (current word, current level)
        queue<pair<string, int>> q;
        q.push({beginWord, 1}); // Start with beginWord at level 1

        // BFS
        while (!q.empty()) {
            auto [currentWord, level] = q.front();
            q.pop();

            // Try changing each letter of the current word
            for (int i = 0; i < currentWord.size(); ++i) {
                char originalChar = currentWord[i];

                // Change each character to every possible lowercase letter
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == originalChar) continue; // Skip the original character

                    currentWord[i] = c;

                    // If the new word is the end word, return the level + 1
                    if (currentWord == endWord) {
                        return level + 1;
                    }

                    // If the new word is in the word set, add it to the queue and mark it as visited
                    if (wordSet.find(currentWord) != wordSet.end()) {
                        q.push({currentWord, level + 1});
                        wordSet.erase(currentWord); // Remove from set to prevent revisiting
                    }
                }

                // Restore the original character
                currentWord[i] = originalChar;
            }
        }

        // If BFS completes without finding the endWord, return 0
        return 0;
    }
};

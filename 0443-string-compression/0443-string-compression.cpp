class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0; // Index to update the result
        int i = 0; // Start of the current group

        while (i < n) {
            int j = i;
            while (j < n && chars[j] == chars[i]) {
                j++;
            }
            chars[index++] = chars[i]; // Write the character

            if (j - i > 1) { // If group length is more than 1
                string count = to_string(j - i); // Convert count to string
                for (char c : count) {
                    chars[index++] = c; // Write the count
                }
            }

            i = j; // Move to the next group
        }

        return index; // Return the new length of the array
    }
};

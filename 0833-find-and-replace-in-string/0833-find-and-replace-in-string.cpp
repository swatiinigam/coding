class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string ans;
        int n = s.size();
        int i = 0;
        while (i < n) {
            bool found = false;
            for (int j = 0; j < indices.size(); j++) {
                if (i == indices[j] && s.substr(i, sources[j].size()) == sources[j]) {
                    ans += targets[j];
                    i += sources[j].size();
                    found = true;
                    break;
                }
            }
            if (!found) {
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
};

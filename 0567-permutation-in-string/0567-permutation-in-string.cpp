class Solution {
private:
    bool isPermutation(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        if(s1.size()>s2.size()){
      return false;
        }
        for (int i = 0; i <= s2.size() - n; i++) {
            string substr = s2.substr(i, n);
            if (isPermutation(s1, substr)) {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    int rank(unordered_map<int, int>& mp, int a) {
        return mp.count(a) ? mp[a] : mp.size();
    }
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        for(int i = 0; i < arr2.size(); i++) {
            mp[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&](int a, int b) {
            return rank(mp, a) == rank(mp, b) ? a < b : rank(mp, a) < rank(mp, b);
        });
        return arr1;
    }
};
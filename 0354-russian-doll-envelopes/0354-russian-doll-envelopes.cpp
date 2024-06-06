class Solution {
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);

        vector<int> v;
        for(auto e : envelopes) {
            if(!v.size() || v.back() < e[1]) v.push_back(e[1]);
            else {
                int pos = lower_bound(v.begin(), v.end(), e[1]) - v.begin();
                v[pos] = e[1];
            }
        }
        return v.size();
    }
};

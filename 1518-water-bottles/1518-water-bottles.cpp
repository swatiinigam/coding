class Solution {
public:
    static int exchange(int n, int k){
        if (n<k) return 0;
        auto [n0, r]=div(n, k);
        return n0+exchange(n0+r, k);
    }
    static int numWaterBottles(int n, int k) {
        return n+exchange(n, k);
    }
};




auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

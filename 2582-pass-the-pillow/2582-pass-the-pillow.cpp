class Solution {
public:
    int passThePillow(int n, int time) {
        if(time < n) return time + 1;

        int q = time / (n-1);
        if(q%2 == 0) {
            return 1 + time%(n-1);
        }

        return n - time%(n-1);
    }
};
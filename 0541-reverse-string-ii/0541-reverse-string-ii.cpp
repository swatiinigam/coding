class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.size();
        for(int i=0;i<n;i+=k*2){
      int left=i;
            int right=min(i+k-1,n-1);
            while(left<=right){
            swap(s[left++],s[right--]);
            }
        }
        return s;
    }
};
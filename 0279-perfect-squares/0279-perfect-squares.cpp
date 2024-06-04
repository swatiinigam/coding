/*class Solution {
    
    private:
    int solve(int n,int num,int cnt )
    {
        int mini =INT_MAX;
      if(n==num){
          return cnt;
      }
        for(int i=1;i<n;i++){
     int minicnt=   solve(n,num-i*i,cnt+1);
            if(minicnt<mini){
          mini=minicnt;
            }
    }
    }
public:
    int numSquares(int n) {
        
    }
};
*/
class Solution {
public:
int solve(int n)
{
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
    for(int j = 1;j<=n;j++)
    {
        int mini = INT_MAX;
        for(int i = 1;i<=sqrt(j);i++)
       {
           int sq = i*i;
           int curr = 1 + dp[j - sq];
           mini = min(mini,curr);
       }
       dp[j] = mini;
    }
    return dp[n];
}
    int numSquares(int n) 
    {
        return solve(n);
    }
};
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        long long currentTime = 0;
        long long totalWaitingTime = 0;
        
        for (int i = 0; i < n; ++i) {
            int arrival = customers[i][0];
            int timeToPrepare = customers[i][1];
            
            if (currentTime < arrival) {
                currentTime = arrival;
            }
            currentTime += timeToPrepare;
            totalWaitingTime += (currentTime - arrival);
        }
        
        return (double)totalWaitingTime / n;
    }
};;
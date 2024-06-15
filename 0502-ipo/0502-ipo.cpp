class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<vector<int>> projects;
        for(int i = 0; i < profits.size(); i++) {
            projects.push_back({capital[i], profits[i]});
        }
        
        sort(projects.begin(), projects.end());
        priority_queue<int> maxHeap;
        for(int i = 0; i < projects.size(); i++) {
            if(w >= projects[i][0]) {
                maxHeap.push(projects[i][1]);
            } else if(k > 0 && maxHeap.size() > 0) {
                k--;
                i--;
                w += maxHeap.top();
                maxHeap.pop();
            }
        }
        
        while(maxHeap.size() > 0 && k > 0) {
            w += maxHeap.top();
            maxHeap.pop();
            k--;
        }
        return w;
    }
};
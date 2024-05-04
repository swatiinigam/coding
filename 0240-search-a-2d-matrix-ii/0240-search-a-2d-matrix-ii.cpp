class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int rowind=0;
        int colind=col-1;
        while(rowind<row && colind>=0){
          int element=matrix[rowind][colind];
            if(element==target){
            return 1;
            }
            else if(element<target){
             rowind++;
            }
            else if(element>target){
            colind--;
            }
        }
        return 0;
    }
};
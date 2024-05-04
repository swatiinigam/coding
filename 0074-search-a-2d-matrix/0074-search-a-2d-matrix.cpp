class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int row=matrix.size();
         int col=matrix[0].size();
         int s=0;
        int e=row*col-1;
      
        while(s<=e){
            int mid=s+(e-s)/2;
            int ro=mid/col;
            int co=mid%col;
            if(matrix[ro][co]==target){
              return true;
            }
            else if(matrix[ro][co]>=target){
              e=mid-1;
            }
            else if(matrix[ro][co]<=target){
            s=mid+1;
            }
        }
        return false;
    }
};
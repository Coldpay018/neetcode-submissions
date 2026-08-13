class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int col_size = matrix[0].size();
        int high = matrix.size()*matrix[0].size()-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int row = mid / col_size;
            int col = mid % col_size;
            if(matrix[row][col]==target)
                return true;
            else if(matrix[row][col]>target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col = matrix[0].size()-1;
        int i = 0;
        int m = matrix.size()-1;
        int greater = matrix[i][col];
        while(i<=m && greater<=target)
        {
            if(matrix[i][col]==target)
                return true;
            else if(i+1<=m){
                i++;
                greater = matrix[i][col];
            }
            else
                return false;
        }
        int low = 0;
        int high = matrix[0].size()-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(matrix[i][mid]==target)
                return true;
            else if(matrix[i][mid]<target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};

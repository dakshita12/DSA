class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> result;

        int m = matrix.size()-1;
        int n = matrix[0].size()-1;

        int top = 0;
        int bottom = m;
        int left = 0;
        int right = n;

        while(top<=bottom && left<=right){

            // Traverse from left to right across top row
            for(int i=left; i<=right; i++){
                result.push_back(matrix[top][i]);
            }
            top++;


            // Traverse from top to bottom across right column 
            for(int i=top; i<=bottom; i++){
                result.push_back(matrix[i][right]);
            }
            right--;


            // Traverse from right to left across bottom row
            if(top<=bottom){
                for(int i=right; i>=left; i--){
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }


            // Traverse from bottom to top across left column 
            if(left<=right){
                for(int i=bottom; i>=top; i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return result;
    }
};
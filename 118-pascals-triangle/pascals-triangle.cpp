class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0; i<numRows; i++){
            int a=1;
            vector<int> temp;
            for(int j=0; j<=i; j++){
                if(j==0){
                    temp.push_back(a);
                }
                else{
                    a = a*(i-j+1)/j;
                    temp.push_back(a);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
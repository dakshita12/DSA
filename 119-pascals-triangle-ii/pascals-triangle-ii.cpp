class Solution {
public:
    vector<int> getRow(int rowIndex) {
       
            long long a=1;
            vector<int> temp;
            for(int j=0; j<=rowIndex; j++){
                if(j==0){
                    temp.push_back(a);
                }
                else{
                    a = a*(rowIndex-j+1)/j;
                    temp.push_back(a);
                }
            }
        
        return temp;
    }
};
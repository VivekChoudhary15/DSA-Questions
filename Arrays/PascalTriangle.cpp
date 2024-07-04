#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<int>> PascalTriangle(int numRows){
        vector<vector<int>> result;
        vector<int> prevRow;

        for (int i=0; i<numRows; i++){
            vector<int> currRow(i+1,1);
            for (int j=0; j<i; j++){
                currRow[j]=prevRow[j]+prevRow[j-1];
            }

            result.push_back(currRow);
            prevRow=currRow;
        }
        return result;
    }
};
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int columns=matrix[0].size();

        vector<int> rowVector(rows,1);
        vector<int> colVector(columns,1);

        for (int i=0; i<rows; i++){
            for (int j=0; j<columns; j++){
                if (matrix[i][j]==0){
                    rowVector[i]=0;
                    colVector[j]=0;
                }
            }
        }

        for (int i=0; i<rows; i++){
            if(rowVector[i]==0){
                for (int j=0; j<columns; j++){
                    matrix[i][j]=0;
                }
            }
        }
        
        for (int i=0; i<columns; i++){
            if (colVector[i]==0){
                for (int j=0; j<rows; j++){
                    matrix[j][i]=0;
                }
            }
        }

        return ;

    }
};

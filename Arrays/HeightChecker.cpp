#include <iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        int maxi = INT_MIN;
        for (int i=0; i<n; i++){
            maxi = max(heights[i], maxi);
        }

        vector<int> countArr(maxi+1, 0);

        for (int i=0; i<n; i++){
            countArr[heights[i]]++;
        }

        // CumSum
        for (int i=1; i<=maxi; i++){
            countArr[i] = countArr[i]+countArr[i-1];
        }

        vector<int> sortedArr(n);
        for (int i=n-1; i>=0; i--){
            sortedArr[countArr[heights[i]-1]]=heights[i];
            countArr[heights[i]]--;
        }
        
        int answer=0;
        for (int i=0; i<n; i++){
            if (sortedArr[i]!=heights[i]){
                answer++;
            }
        }
        
        return answer;
    }
};
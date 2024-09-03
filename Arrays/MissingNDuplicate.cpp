// P.S:-https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-missing-and-repeating

#include<iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        vector<int> result;
        
        for (int i=0; i<n; i++){
            if (arr[abs(arr[i])-1]>0){
                arr[abs(arr[i])-1]=-arr[abs(arr[i]-1)];
            }else {
                result.push_back(abs(arr[i]));
            }
        }
        for (int i=0; i<n; i++){
            if (arr[i]>0) result.push_back(i+1); 
        }
        return result;
    }
};

int main() {
    Solution sol;
    
    vector<int> arr = {4, 3, 6, 2, 1, 1};  // Example array
    int n = arr.size();                    // Size of the array
    
    vector<int> result = sol.findTwoElement(arr, n);
    
    cout << "Duplicate element: " << result[0] << endl;
    cout << "Missing element: " << result[1] << endl;
    
    return 0;
}

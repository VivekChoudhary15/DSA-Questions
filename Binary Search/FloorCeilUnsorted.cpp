// P.S.:- https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=ceil-the-floor

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // int floor=INT_MIN;
        // int ceil=INT_MAX;
        vector<int> result={INT_MIN,INT_MAX};
        
        for (int i=0; i<arr.size(); i++){
            if (arr[i]==x){
                result[1]=x;
                result[0]=x;
                return result;
            }else if (arr[i]<x){
                result[0]=max(arr[i], result[0]);
            }else{
                result[1]=min(arr[i], result[1]);
            }
        }
        
        if (result[0]==INT_MIN){
            result[0]=-1;
        }if (result[1]==INT_MAX){
            result[1]=-1;
        }
        return result;
    }
};


int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}

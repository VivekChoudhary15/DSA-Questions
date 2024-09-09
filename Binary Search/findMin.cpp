// P.S:-https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& arr) {
        int left=0;
        int right=arr.size()-1;
        int ans=INT_MAX;
        while (left<=right){
            int mid=left+(right-left)/2;
            if (arr[mid]>=arr[left]){
                ans=min(arr[left], ans);
                left=mid+1;
            }else{
                ans=min(arr[mid], ans);
                right=mid-1;
            }
        }return ans;
    }
};

int main() {
    Solution sol;
    
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    
    int minElement = sol.findMin(arr);
    
    cout << "The minimum element is: " << minElement << endl;
    
    return 0;
}

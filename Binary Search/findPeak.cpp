#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        while (left<right){
            int mid=left+(right-left)/2;

            if (nums[mid]<nums[mid+1]){
                left=mid+1;
            }else{
                right=mid;
            }
        }
        return left;
    }
};

int main() {
    Solution sol;

    // Test case: Input array where the peak element exists
    vector<int> nums = {1, 2, 3, 1};  // Peak is at index 2

    // Call the function
    int peakIndex = sol.findPeakElement(nums);

    // Output the result
    cout << "The peak element is at index: " << peakIndex << endl;
    cout << "The peak element is: " << nums[peakIndex] << endl;

    return 0;
}

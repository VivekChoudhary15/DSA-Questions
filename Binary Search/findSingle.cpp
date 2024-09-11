#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;

        while (left<right){
            int mid=left+(right-left)/2;

            if (mid%2==1){
                mid--;
            }
            if (nums[mid]==nums[mid+1]){
                left=mid+2;
            }else{
                right=mid;
            }
        }return nums[left];
    }
};

int main() {
    Solution sol;

    // Test case: Input array with a single non-duplicate element
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5};

    // Call the function
    int result = sol.singleNonDuplicate(nums);

    // Output the result
    cout << "The single non-duplicate element is: " << result << endl;

    return 0;
}

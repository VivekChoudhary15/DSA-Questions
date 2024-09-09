#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return true;
            }

            if (nums[left] == nums[mid] && nums[right] == nums[mid]) {
                left++;
                right--;
            }
            else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;

    if (sol.search(nums, target)) {
        cout << "Target " << target << " found in the array!" << endl;
    } else {
        cout << "Target " << target << " not found in the array." << endl;
    }

    target = 3; 

    if (sol.search(nums, target)) {
        cout << "Target " << target << " found in the array!" << endl;
    } else {
        cout << "Target " << target << " not found in the array." << endl;
    }

    return 0;
}

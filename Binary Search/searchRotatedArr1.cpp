#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;

            if (nums[mid]==target){
                return mid;
            }else if (nums[mid]>=nums[left]){
                if (nums[left]<=target && nums[mid]>=target){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }else {
                if (nums[mid]<=target && target<=nums[right]){
                    left=mid+1;
                }else{
                    right=mid-1;
                }

            }
        }return -1;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    
    int result = sol.search(nums, target);
    
    if (result != -1) {
        cout << "Target found at index " << result << endl;
    } else {
        cout << "Target not found." << endl;
    }

    return 0;
}

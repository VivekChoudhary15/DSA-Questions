// P.S:-https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while (left<=right){
            int mid=left+(right-left)/2;
            if (nums[mid]==target){
                int l=mid;
                int r=mid;
                while( l>0 && nums[l-1]==target){
                    l--;
                }while(r<nums.size()-1 && nums[r+1]==target){
                    r++;
                }return{l,r};
            }else if (nums[mid]>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return {-1,-1};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = sol.searchRange(nums, target);

    cout << "Range: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}

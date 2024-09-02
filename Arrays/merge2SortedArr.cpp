#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] >= nums2[j]) {
                result.push_back(nums2[j]);
                j++;
            } else {
                result.push_back(nums1[i]);
                i++;
            }
        }
        while (i < m) {
            result.push_back(nums1[i]);
            i++;
        }
        while (j < n) {
            result.push_back(nums2[j]);
            j++;
        }

        for (int i = 0; i < m + n; i++) {
            nums1[i] = result[i];
        }
    }
};

int main() {
    // Example input
    vector<int> nums1 = {1, 2, 3, 0, 0, 0}; // nums1 has size m + n, with extra space for nums2
    int m = 3;  // Number of initialized elements in nums1
    vector<int> nums2 = {2, 5, 6}; // nums2 has n elements
    int n = 3;  // Number of elements in nums2

    Solution sol;
    sol.merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

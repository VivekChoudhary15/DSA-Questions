// P.S.:-https://leetcode.com/problems/maximum-product-subarray/description/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN;
        int product=1;

        for (int i=0; i<nums.size(); i++){
            product*=nums[i];
            maxi=max(product, maxi);
            if (product==0){
                product=1;
            }
        }      
        product=1;
        for(int i=nums.size()-1; i>=0; i--){
            product*=nums[i];
            maxi=max(product, maxi);
            if (product==0){
                product=1;
            }
        }
        return maxi;
    }
};

int main() {
    Solution solution;

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = solution.maxProduct(nums);
    cout << "Maximum product of a subarray: " << result << endl;

    return 0;
}

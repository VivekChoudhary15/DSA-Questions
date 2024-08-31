// P.S.:- https://leetcode.com/problems/subarray-sum-equals-k/description/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mpp;
        mpp[0]=1;
        int prefixsum=0; 
        int cnt=0;

        for (int i=0; i<nums.size(); i++){
            prefixsum+=nums[i];
            int remove = prefixsum-k;
            cnt+=mpp[remove];
            mpp[prefixsum]+=1;
        }
        return cnt;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 5;

    Solution solution;
    int result = solution.subarraySum(nums, k);
    cout << "Number of subarrays with sum " << k << " is: " << result << endl;
    return 0;
}

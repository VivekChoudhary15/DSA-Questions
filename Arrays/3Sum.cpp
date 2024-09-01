#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n=nums.size();

        for (int i=0; i<n; i++){
            if (i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1;
            int k=n-1;
            while (j<k){
                int total=nums[i]+nums[j]+nums[k];
                if (total<0){
                    j++;
                }else if (total>0){
                    k--;
                }else{
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (j<k && nums[j]==nums[j-1]){
                        j++;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    Solution sol;

    vector<vector<int>> result = sol.threeSum(nums);

    cout << "Unique triplets that sum to zero are: " << endl;
    for (const auto& triplet : result) {
        cout << "[";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}

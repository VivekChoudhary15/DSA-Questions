#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j-1]) {
                    continue;
                }
                int s = j + 1;
                int e = n - 1;
                long long currTarget = (long long)target - nums[i] - nums[j];

                while (s < e) {
                    int sum = nums[s] + nums[e];
                    if (sum < currTarget) {
                        s++;
                    } else if (sum > currTarget) {
                        e--;
                    } else {
                        result.push_back({nums[i], nums[j], nums[s], nums[e]});
                        while (s < e && nums[s] == nums[s + 1]) {
                            s++;
                        }
                        while (s < e && nums[e] == nums[e - 1]) {
                            e--;
                        }
                        s++;
                        e--;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    Solution sol;

    vector<vector<int>> result = sol.fourSum(nums, target);

    cout << "Quadruplets that sum to " << target << " are: " << endl;
    for (const auto& quadruplet : result) {
        cout << "[";
        for (int num : quadruplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}

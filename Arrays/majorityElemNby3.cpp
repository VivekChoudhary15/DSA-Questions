#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0;
        int cnt2=0;
        int el1=INT_MIN, el2=INT_MIN;
        vector<int> result;

        for (int i=0; i<nums.size(); i++){
            if (cnt1==0 && nums[i]!=el2){
                cnt1+=1;
                el1=nums[i];
            }else if (cnt2==0 && nums[i]!=el1){
                cnt2+=1;
                el2=nums[i];
            }else if (nums[i]==el1){
                cnt1 ++;
            }else if (nums[i]==el2){
                cnt2++;
            }else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1=0;
        cnt2=0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i]==el1) cnt1++;
            else if (nums[i]==el2) cnt2++;
        }

        if (cnt1>nums.size()/3) result.push_back(el1);
        if (cnt2>nums.size()/3) result.push_back(el2);
        return result;
    }
};

int main() {
    vector<int> nums = {3, 2, 3, 1, 2, 2, 2};

    Solution solution;

    vector<int> result = solution.majorityElement(nums);

    cout << "Majority elements (more than n/3 times) are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

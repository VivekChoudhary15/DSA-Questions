#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    void moveZeroes(vector<int>& nums){
        vector<int> ans(nums.size(),0);
        int j=0;

        for (int i=0; i<nums.size(); i++){
            if (nums[i]!=0){
                ans[j]=nums[i];
                j++;
            }
        }

        for (int i=0; i<nums.size(); i++){
            nums[i]=ans[i];
        }
        return;

    }
};
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0; 
        int n=nums.size();
        int rsum=(n*(n-1))/2;

        for (int i=0; i<n; i++){
            sum=sum+nums[i];
        }
        return rsum-sum;

    }
};
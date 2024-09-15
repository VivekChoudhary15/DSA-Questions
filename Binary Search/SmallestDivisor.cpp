//P.S.:- https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

#include<algorithm>

class Solution {

    int sumDiv(vector<int> &nums, int divisor){
        int sum=0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]%divisor==0){
                sum+=nums[i]/divisor;
            }else{
                sum+=1;
                sum+=nums[i]/divisor;
            }
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left=1;
        int right = *max_element(nums.begin(), nums.end());
        int possible=0;

        while(left<=right){
            int mid=left+(right-left)/2;

            if(sumDiv(nums, mid)>threshold){
                left=mid+1;
            }else{
                right=mid-1;
                possible=mid;
            }
        }
        return possible;
    }
};

// P.S.:-https://leetcode.com/problems/reverse-pairs/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int> &nums, int low, int mid, int high, int &pairs){
        int x=mid+1;
        for (int i=low; i<=mid; i++){
            while (x<=high && nums[i]>2*(long long)nums[x]){
                x++;
            }pairs+=x-(mid+1);
        }

        int size=high-low+1;
        vector<int> temp(size,0);
        int i=low; 
        int j=mid+1;
        int k=0;

        while(i<=mid && j<=high){
            if (nums[i]<nums[j]){
                temp[k++]=nums[i++];
            }else{
                temp[k++]=nums[j++];
            }
        }

        while (i<=mid){
            temp[k++]=nums[i++];
        }while (j<=high){
            temp[k++]=nums[j++];
        }

        int m=0;
        for (int i=low; i<=high; i++){
            nums[i]=temp[m++];
        }
    }

    void mergeSort(vector<int> &nums, int left, int right, int &pairs){
        if (left>=right){
            return;
        }
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid, pairs);
        mergeSort(nums, mid+1, right, pairs);
        merge(nums, left, mid, right, pairs);
    }


    int reversePairs(vector<int>& nums) {
        int pairs=0;
        mergeSort(nums, 0, nums.size()-1, pairs);
        return pairs;
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

    int result = solution.reversePairs(nums);
    cout << "Number of reverse pairs: " << result << endl;

    return 0;
}

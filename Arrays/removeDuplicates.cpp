// You are given a sorted integer array with duplicates in non decreasing order
// You need to remove the duplicates and return the length of unique numbers in the array

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        ans[0]=nums[0];
        int i=1;
        int j=1;

        while (i<n){
            if(nums[i]==ans[j-1]){
                i++;
            }else{
                ans[j] = nums[i];
                j++;
                i++;
            }
        }

        for (int i=0; i<n; i++){
            nums[i] = ans[i];
        }

        return j;
    }
};

int main(){
    Solution sol;
    vector<int> num = {0,0,1,1,1,2,2,2,2,3};

    int k=sol.removeDuplicates(num);
    cout<<k<<endl;
    for (int i=0; i<num.size(); i++){
        cout<<num[i]<<" ";
    }cout<<endl;
}

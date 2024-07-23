// P.S.: https://leetcode.com/problems/next-greater-element-i/

#include<iostream>
#include<vector>
#include<stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mp;

        for(int i=nums2.size()-1;i>=0;i--) {
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            if(st.empty()) {
                mp[nums2[i]]=-1;
            }
            else {
                mp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }

        vector<int> ans;
        for(int i=0;i<nums1.size();i++) {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};

int main() {
    vector<int> arr = {4, 8, 5, 2, 25};
    int n = arr.size();

    vector<int> result = nextGreaterElement(arr, n);

    cout << "Next smaller elements: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

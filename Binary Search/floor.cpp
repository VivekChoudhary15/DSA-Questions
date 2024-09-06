#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> &v, long long n, long long x) {
        int lowerIndex=-1;
        long long left=0;
        long long right=n-1;
        
        while (left<=right){
            int mid=left+(right-left)/2;
            if (v[mid]==x){
                return mid;
            }
            else if (v[mid]>x){
                right=mid-1;
            }else{
                lowerIndex=mid;
                left=mid+1;
            }
        }return lowerIndex;
    }
};

int main() {
    Solution solution;
    
    vector<long long> v = {1, 2, 8, 10, 12, 19};
    long long n = v.size();
    long long x = 5;

    int result = solution.findFloor(v, n, x);
    if (result != -1) {
        cout << "The floor of " << x << " is " << v[result] << " at index " << result << endl;
    } else {
        cout << "Floor of " << x << " doesn't exist in the array." << endl;
    }

    return 0;
}

#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    long long int floorSqrt(long long int n) {
        long long int low=1;
        long long int high=n;
        long long int ans;
        while (low<=high){
            long long int mid=low+(high-low)/2;
            
            if (mid*mid==n){
                return mid;
            }else if (mid*mid<n){
                low=mid+1;
                ans=mid;
            }else {
                high=mid-1;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    long long int n;
    
    cout << "Enter a number to find its floor square root: ";
    cin >> n;
    
    long long int result = solution.floorSqrt(n);
    
    cout << "The floor square root of " << n << " is: " << result << endl;
    
    return 0;
}

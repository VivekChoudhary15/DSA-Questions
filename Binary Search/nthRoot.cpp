#include <iostream>
#include <cmath>  // For pow() function
using namespace std;

class Solution{
    public:
    int NthRoot(int n, int m) {
        int left = 1;
        int right = m;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            long long midPow = pow(mid, n);
            
            if(midPow == m) {
                return mid;
            } else if(midPow > m) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    int n, m;
    
    cout << "Enter the value of n (root degree): ";
    cin >> n;
    cout << "Enter the value of m (number): ";
    cin >> m;
    
    int result = solution.NthRoot(n, m);
    
    if (result == -1) {
        cout << "No integer Nth root exists for " << m << " with root degree " << n << "." << endl;
    } else {
        cout << "The " << n << "

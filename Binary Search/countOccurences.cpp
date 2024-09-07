// P.S:-https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-occurrence

#include<iostream>
using namespace std;

class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
        int left=0;
        int right=n-1;
        int cnt=0;
        while (left<=right){
            int mid=left+(right-left)/2;
            if (arr[mid]==x){
                int l=mid;
                cnt++;
                int r=mid;
                while (l>0 && arr[l-1]==x){
                    l--;
                    cnt++;
                }while(r<n-1 && arr[r+1]==x){
                    r++;
                    cnt++;
                }return cnt;
            }else if (arr[mid]>x){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }return cnt;
	}
};

int main() {
    Solution sol;

    int arr[] = {1, 2, 2, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int x = 2;  
  
    int result = sol.count(arr, n, x);

    if (result == 0) {
        cout << "Element " << x << " is not present in the array." << endl;
    } else {
        cout << "Element " << x << " occurs " << result << " times in the array." << endl;
    }

    return 0;
}

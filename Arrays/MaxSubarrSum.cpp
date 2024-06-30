// Kadane's Algorithm

#include <iostream>
using namespace std;
#include <vector>

// To find the maximum subarray sum

int MaxSubarraySum (vector<int> arr){
    int n=arr.size();
    int currMax=arr[0];
    int maxSoFar=arr[0];

    for (int i=0; i<n; i++){
        currMax = max(arr[i], arr[i]+currMax);
        maxSoFar = max(currMax, maxSoFar);
    }
    return maxSoFar;

}

int main(){
    vector <int> arr={-2,-3,5,-1,-2,1,5,-3};
    int sum=MaxSubarraySum(arr);
    cout<<sum<<endl;
}
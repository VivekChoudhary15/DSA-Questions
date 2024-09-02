#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int subarraysWithXorK(vector<int> arr, int n, int k){
  int xr=0;
  int cnt=0;
  unordered_map<int,int> mpp;
  mpp[0]=1;

  for (int i=0; i<n; i++){
    xr=xr^arr[i];
    int x=xr^k;
    cnt+=mpp[x];
    mpp[xr]++;
  }
  return cnt;
}

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}

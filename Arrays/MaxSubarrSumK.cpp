// P.S.: https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-sub-array-with-sum-k

class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int N, int K) 
    { 
        int left=0, right=0;
        int sum=arr[0];
        int length=0;
        while (right<N){
            while (left<=right && sum>K){
                sum-=arr[left];
                left++;
            }
        }
        if (sum==K){
            length=max(length, right-left+1);
        }
        right++;
        if (right<N){
            sum+=arr[right];
        }
        return length;
    } 

};

P.S.:- https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=inversion-of-array

class Solution {
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[], long long temp[], int left, int mid, int right){
        int i=left;
        int j=mid+1;
        int k=left;
        long long inversions=0;
        
        while ((i<=mid)&& (j<=right)){
            if (arr[i]<=arr[j]){
                temp[k++]=arr[i++];
            }else{
                temp[k++]=arr[j++];
                inversions+=(mid-i+1);
            }
        }
        
        while (i<=mid){
            temp[k++]=arr[i++];
        }
        
        while (j<=right){
            temp[k++]=arr[j++];
        }
        
        for (int i=left; i<=right; i++){
            arr[i]=temp[i];
        }
            
        return inversions;
    }
    
    long long mergeSort(long long arr[], long long temp[], int left , int right){
        long long inversions=0;
        if(left<right){
            int mid=(left+right)/2;
            
            inversions+=mergeSort(arr, temp, left, mid);
            inversions+=mergeSort(arr, temp, mid+1, right);
            
            inversions+=merge(arr, temp, left, mid, right);
        }
        return inversions;
    }
    
    long long int inversionCount(long long arr[], int n) {
        long long temp[n];
        return mergeSort(arr, temp, 0, n-1);
        
    }
};

int main() {
    Solution solution;

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    long long arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long result = solution.inversionCount(arr, n);
    cout << "Number of inversions: " << result << endl;

    return 0;
}

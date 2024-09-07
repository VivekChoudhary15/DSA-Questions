// Find the kth minimum element in the array

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;  

    for (int j = left; j < right; ++j) {
        if (arr[j] <= pivot) {  
            i++;
            swap(arr[i], arr[j]);  
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;  
}

int quickselect(vector<int>& arr, int left, int right, int k) {

    if (left == right)
        return arr[left];
    
    int pivotIndex = partition(arr, left, right);

    int kIndex = k - 1;

    if (pivotIndex == kIndex)
        return arr[pivotIndex];
    else if (pivotIndex > kIndex)
        return quickselect(arr, left, pivotIndex - 1, k);
    else
        return quickselect(arr, pivotIndex + 1, right, k);
}

int main() {
    vector<int> arr = {10, 4, 5, 8, 6, 11, 26};
    int k = 3;
    
    int result = quickselect(arr, 0, arr.size() - 1, k);
    cout << "The 3rd smallest element is: " << result << endl;

    return 0;
}

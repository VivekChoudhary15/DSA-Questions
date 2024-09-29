// P.S.:- https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

class Solution {
    int func(vector<int>& weights, int capacity){
        int days=1;
        int load=0;

        for (int i=0; i<weights.size(); i++){
            if (load+weights[i]<=capacity){
                load+=weights[i];
                // days++;
            }else{
                days++;
                load=weights[i];
            }
        }return days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(), weights.end());
        int high=accumulate(weights.begin(), weights.end(), 0);

        while(low<=high){
            int mid=low+(high-low)/2;
            int day=func(weights, mid);
            if (day<=days){
                high=mid-1;
            }else {
                low=mid+1;
            }
        }return low;
    }
};

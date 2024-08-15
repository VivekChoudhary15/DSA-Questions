#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        
        sort(intervals.begin(), intervals.end(),[](const vector<int> &a, const vector<int> &b){
            return a[0]<b[0];
        });

        vector<int> prev = intervals[0];
        
        for (int i = 1; i < intervals.size(); i++) {
            vector<int> interval = intervals[i];

            if (interval[0] <= prev[1]) {
                prev[1] = max(prev[1], interval[1]);
            }else {
                result.push_back(prev);
                prev = interval;
            }
        }

        result.push_back(prev);
        return result;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> mergedIntervals = sol.merge(intervals);

    cout << "Merged Intervals: " << endl;
    for (const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}

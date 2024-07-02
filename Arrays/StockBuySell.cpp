#include <iostream>
#include <vector>
using namespace std;
#include <climits>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int profit=0;

        for (int i=0; i<prices.size(); i++){
            if (prices[i]<buy){
                buy=prices[i];
            }
            else if(prices[i]-buy>profit){
                profit=prices[i]-buy;
            }
        }
        return profit;
    }
};

int main() {
    Solution sol;
    vector<int> stockPrices = {100, 180, 260, 310, 40, 535, 695};
    int result = sol.maxProfit(stockPrices);
    cout << "Maximum profit: " << result << endl;
    return 0;
}
// P.S.:-https://leetcode.com/problems/koko-eating-bananas/description/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    bool check(vector<int> &piles, int n, int h, int mid){
        int ans=0;
        for (int i=0; i<n; i++){
            ans+=(piles[i]/mid);
            if(piles[i]%mid!=0){
                ans++;
            }
        }
        if (ans<=h){
            return true;
        }return false;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int pilesMax=piles[0];
        for (int i=0; i<n; i++){
            pilesMax=max(pilesMax, piles[i]);
        }

        int high=pilesMax;
        while (low<high){
            int mid=low+(high-low)/2;

            if (check(piles, n, h, mid)){
                high=mid;
            }else{
                low=mid+1;
            }
        }return low;
    }
};

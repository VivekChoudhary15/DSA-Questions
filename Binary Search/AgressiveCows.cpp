// P.S:-https://www.spoj.com/problems/AGGRCOW/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canWeplace(vector<int> &stalls,int distance, int cows){
    int cowcnt=1;
    int last=stalls[0];

    for (int i=1; i<stalls.size(); i++){
        if (stalls[i]-last>=distance){
            cowcnt++;
            last=stalls[i];
        }
        if (cowcnt==cows){
            return true;
        }
    }
    return false;
}

int main(){
    int testcases;
    cin>>testcases;
    vector<int> result(testcases);

    for (int i=0; i<testcases; i++){
        int arrsize;
        cin>> arrsize;
        int cows;
        vector<int> stalls(arrsize);
        
        cin>> cows;
        for (int j=0; j<arrsize; j++){
            int element;
            cin>>element;
            stalls[j]=element;
        }
        sort(stalls.begin(), stalls.end());
        int left=1;
        int right=*max_element(stalls.begin(), stalls.end())-*min_element(stalls.begin(), stalls.end());

        while(left<=right){
            int mid=left+(right-left)/2;
            if (canWeplace(stalls, mid, cows)==true){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }result[i]=right;
    }
    for (int i = 0; i < testcases; i++) {
        cout << result[i] << endl;
    }
}

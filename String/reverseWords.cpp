#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


// class Solution {
// public:
//     string reverseWords(string s) {
//         string ans;
//         string currWord;

//         for (int i=0; i<s.length(); i++){
//             if (s[i]!=' '){
//                 currWord+=s[i];
//             }else{
//                 if (ans!=""){
//                     ans=currWord+" "+ans;
//                 }
//                 else{
//                     ans=currWord;
//                 }currWord="";
//             }
//         }

//         if (currWord!=""){
//             if (ans==""){
//                 ans=currWord;
//             }else{
//                 ans=currWord+ans;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());

        int n=s.size();
        int left=0;
        int right=0;
        int i=0;

        while(i<n){
            while(i<n && s[i]==' '){
                i++;
            }

            if(i==n){
                break;
            }
            
            while(i<n && s[i]!=' '){
                s[right]=s[i];
                right++;
                i++;
            }
            
            reverse(s.begin()+left,s.begin()+right);
            s[right++]=' ';
            left=right;
            i++;
        }
        s.resize(right-1);
        return s;
    }
};

int main(){
    string test="the sky is   blue";
    Solution sol;
    string result=sol.reverseWords(test);
    cout<<result;
    cout<<endl;
}
// You are given Roman Numbers in string format. You need to convert them to integers

// Necessary Libraries
#include <iostream>
#include <string>

using namespace std;

// Solution to the problem
class Solution {
public:
    int romanToInt(string s) {
        int answer=0;
        for (int i=0; i<s.length(); i++){
            if (s[i]=='I'){
                if (s[i+1]=='V' || s[i+1]=='X'){
                    answer-=1;
                }else{
                    answer+=1;
                }
            }

            else if (s[i] == 'V'){
                answer+=5;
            }

            else if (s[i] == 'L'){
                answer+=50;
            }

            else if (s[i] == 'D'){
                answer+=500;
            }

            else if (s[i] == 'M'){
                answer+=1000;
            }



            else if (s[i]=='X'){
                if (s[i+1]=='L' || s[i+1]=='C'){
                    answer-=10;
                }else{
                    answer+=10;
                }
            }

            else if (s[i]=='C'){
                if (s[i+1]=='D' || s[i+1]=='M'){
                    answer-=100;
                }else{
                    answer+=100;
                }
            }
            

        }
        return answer;
    }
};

// Use Testcase
int main(){
    Solution sol;
    string s = "MCMVIII";
    int answer = sol.romanToInt(s);
    cout<<answer<<endl;
}
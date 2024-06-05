#include <iostream>
using namespace std;
#include <string>

int number(string s, string t){
    int answer=0;
    for (int i=0; i<t.length(); i++){
        int k=0;
        for (int j=0; j<s.length(); j++){
            if (t[i]==s[i]){
                break;
            }else{
                k++;
            }
        }
        if (k==s.length()){
            answer++;
        }
    }

    return answer;
}

int main(){
    string s,t;
    cin>>s;
    cin>>t;
    cout<<number(s,t);
}
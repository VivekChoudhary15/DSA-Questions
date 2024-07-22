#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                }
                if ((c == ')' && st.top() == '(') ||
                    (c == '}' && st.top() == '{') ||
                    (c == ']' && st.top() == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        
        return st.empty();
    }
};

int main() {
    Solution sol;

    // Test cases
    string test1 = "()";
    string test2 = "()[]{}";
    string test3 = "(]";
    string test4 = "([)]";
    string test5 = "{[]}";

    cout << boolalpha; // to print 'true' or 'false' instead of 1 and 0
    cout << "Test 1: " << sol.isValid(test1) << endl; // Should print true
    cout << "Test 2: " << sol.isValid(test2) << endl; // Should print true
    cout << "Test 3: " << sol.isValid(test3) << endl; // Should print false
    cout << "Test 4: " << sol.isValid(test4) << endl; // Should print false
    cout << "Test 5: " << sol.isValid(test5) << endl; // Should print true

    return 0;
}

#include <iostream>
#include <stack>
using namespace std;

stack<char> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (c == '(') st.push(c); 
        else if (c == '+' || c == '-') {
            while (!st.empty() && st.top() != '(') {
                cout << st.top();
                st.pop();
            }

            st.push(c);
        }
        else if (c == '*' || c == '/') {
            while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                cout << st.top();
                st.pop();
            }

            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                cout << st.top();
                st.pop();
            }

            st.pop();
        }
        else cout << c;
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }

    return 0;
}
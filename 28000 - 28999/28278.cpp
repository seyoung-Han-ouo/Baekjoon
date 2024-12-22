#include <iostream>
#include <stack>
using namespace std;

stack<int> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    while (N--) {
        int n;
        cin >> n;

        if (n == 1) {
            int x;
            cin >> x;

            st.push(x);
        }
        else if (n == 2) {
            if (st.empty()) cout << "-1\n";
            else {
                cout << st.top() << '\n';
                st.pop();
            }
        }
        else if (n == 3) {
            cout << st.size() << '\n';
        }
        else if (n == 4) {
            cout << (int)st.empty() << '\n';
        }
        else {
            if (st.empty()) cout << "-1\n";
            else cout << st.top() << '\n';
        }
    }

    return 0;
}
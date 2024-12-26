#include <iostream>
#include <stack>
using namespace std;

stack<int> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, now = 1;
    cin >> N;

    while (N--) {
        int n;
        cin >> n;

        if (n == now) now++;
        else st.push(n);

        while (!st.empty()) {
            if (now != st.top()) break;
            else {
                st.pop();
                now++;
            }
        }
    }

    if (st.empty()) cout << "Nice\n";
    else cout << "Sad\n";

    return 0;
}
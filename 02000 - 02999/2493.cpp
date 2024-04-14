#include <iostream>
#include <stack>
using namespace std;

stack<pair<int, int>> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;

        while (!st.empty()) {
            if (st.top().second > num) {
                cout << st.top().first << ' ';
                break;
            }

            st.pop();
        }

        if (st.empty()) cout << "0 ";

        st.push({ i, num });
    }

    return 0;
}
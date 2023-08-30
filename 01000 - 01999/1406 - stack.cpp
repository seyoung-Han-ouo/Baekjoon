#include <iostream>
#include <stack>
using namespace std;

stack<char> L, R;

void editor(int M);

void editor(int M) {
    for (int i = 0; i < M; i++) {
        char c;
        cin >> c;

        if (c == 'L' && !L.empty()) {
            R.push(L.top());
            L.pop();
        }
        else if (c == 'D' && !R.empty()) {
            L.push(R.top());
            R.pop();
        }
        else if (c == 'B' && !L.empty()) L.pop();
        else if (c == 'P') {
            char cc;
            cin >> cc;

            L.push(cc);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int M;
    string s;

    cin >> s >> M;;

    for (auto i : s) L.push(i);

    editor(M);

    while (!L.empty()) {
        R.push(L.top());
        L.pop();
    }

    while (!R.empty()) {
        cout << R.top();
        R.pop();
    }
    cout << '\n';

    return 0;
}
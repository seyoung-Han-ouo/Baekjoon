#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    while (N--) {
        string s;
        cin >> s;

        if (s == "push") {
            int x;
            cin >> x;

            q.push(x);
        }
        else if (s == "pop") {
            if (q.empty()) cout << "-1\n";
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (s == "size") {
            cout << q.size() << '\n';
        }
        else if (s == "empty") {
            cout << (int)q.empty() << '\n';
        }
        else if (s == "front") {
            cout << (q.empty() ? -1 : q.front()) << '\n';
        }
        else {
            cout << (q.empty() ? -1 : q.back()) << '\n';
        }
    }

    return 0;
}
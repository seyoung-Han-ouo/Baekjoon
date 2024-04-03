#include <iostream>
#include <set>
using namespace std;

set<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;

        s.insert(n);
    }

    for (auto iter = s.begin(); iter != s.end(); iter++)
        cout << *iter << ' ';

    return 0;
}
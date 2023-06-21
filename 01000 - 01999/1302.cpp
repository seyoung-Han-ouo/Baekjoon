#include <iostream>
#include <map>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, big = 0;
    cin >> N;

    map <string, int> m;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        m[s]++;

        // 가장 큰 값 찾기
        if (big < m[s]) big = m[s];
    }

    // big으로 가장 많이 팔린 책 찾기
    for (auto i = m.begin(); i != m.end(); i++) {
        if (big == i->second) {
            cout << i->first << "\n";
            break;
        }
    }

    return 0;
}
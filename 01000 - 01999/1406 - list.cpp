#include <iostream>
#include <list>
using namespace std;

list<char> L;

void editor(int M);

void editor(int M) {
    list<char>::iterator it = L.end();

    for (int i = 0; i < M; i++) {
        char c;
        cin >> c;

        if (c == 'L' && it != L.begin()) it--;
        else if (c == 'D' && it != L.end()) it++;
        else if (c == 'B' && it != L.begin()) it = L.erase(--it);
        else if (c == 'P') {
            char cc;
            cin >> cc;

            L.insert(it, cc);
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

    for (auto i : s) L.push_back(i);

    editor(M);

    for (auto i : L) cout << i;
    cout << '\n';

    return 0;
}
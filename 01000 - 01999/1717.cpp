#include <iostream>
using namespace std;

int n, m;
int parent[1000001];

int findParent(int n);
bool isSame(int n, int a, int b);

int findParent(int n) {
    if (parent[n] == n) return n;

    return parent[n] = findParent(parent[n]);
}

bool isSame(int n, int a, int b) {
    int aa = findParent(a);
    int bb = findParent(b);

    if (aa == bb) return true;
    else {
        if (n == 0) parent[bb] = aa;

        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i <= n; i++) parent[i] = i;

    while (m--) {
        int n, a, b;
        cin >> n >> a >> b;

        bool same = isSame(n, a, b);

        if (n == 1) {
            if (same) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
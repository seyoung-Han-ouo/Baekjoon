#include <iostream>
#include <vector>
using namespace std;

int N, M;
int parent[500000];

int findParent(int n);
bool isCycle(int a, int b);

int findParent(int n) {
    if (parent[n] == n) return n;

    return parent[n] = findParent(parent[n]);
}

bool isCycle(int a, int b) {
    int aa = findParent(a);
    int bb = findParent(b);

    if (aa == bb) return true;
    else {
        parent[bb] = aa;

        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int result = 0;

    cin >> N >> M;

    for (int i = 0; i < N; i++) parent[i] = i;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        if (isCycle(a, b)) {
            result = i + 1;
            break;
        }
    }

    cout << result << '\n';

    return 0;
}
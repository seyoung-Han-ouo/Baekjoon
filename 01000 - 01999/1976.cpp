#include <iostream>
using namespace std;

int N, M;
int parent[201];
int trip[1000];

int findParent(int n);
void canGo(int a, int b);
bool canPlan();

int findParent(int n) {
    if (parent[n] == n) return n;

    return parent[n] = findParent(parent[n]);
}

void canGo(int a, int b) {
    int aa = findParent(a);
    int bb = findParent(b);

    if (aa != bb) parent[bb] = aa;
}

bool canPlan() {
    for (int i = 1; i < M; i++) {
        int aa = findParent(trip[i - 1]);
        int bb = findParent(trip[i]);

        if (aa != bb) return false;
    }
    
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 201; i++) parent[i] = i;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int num;
            cin >> num;

            if (num == 1) canGo(i, j);
        }
    }

    for (int i = 0; i < M; i++) cin >> trip[i];

    if (canPlan()) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
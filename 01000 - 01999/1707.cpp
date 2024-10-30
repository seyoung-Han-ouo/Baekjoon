#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

#define SIZE 20001

int K, V, E;
vector<int> arr[SIZE];
int check[SIZE];

void bfs(int start);
bool isBinary();

void bfs(int start) {
    queue<int> q;

    q.push(start);
    check[start] = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        // 인접한 그래프 표시하기
        for (int i = 0; i < arr[now].size(); i++) {
            int next = arr[now][i];

            if (check[next] == 0) {
                q.push(next);
                check[next] = (check[now] == 1) ? 2 : 1;
            }
        }
    }
}

// 이 그래프가 이분 그래프인가?
bool isBinary() {
    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (check[i] == check[arr[i][j]]) return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> K;

    while (K--) {
        cin >> V >> E;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;

            arr[u].push_back(v);
            arr[v].push_back(u);
        }

        for (int i = 1; i <= V; i++) {
            if (!check[i]) bfs(i);
        }

        // 출력
        if (isBinary()) cout << "YES\n";
        else cout << "NO\n";

        // 초기화
        for (int i = 1; i <= V; i++) arr[i].clear();
        memset(check, 0, sizeof(check));
    }

    return 0;
}
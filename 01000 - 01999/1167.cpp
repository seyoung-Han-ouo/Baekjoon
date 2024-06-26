#include <iostream>
#include <vector>
using namespace std;

int V, result, lastNode;
vector<vector<pair<int, int>>> edge(100001);
bool check[100001];

void dfs(int now, int sum);

void dfs(int now, int sum) {
    if (result < sum) {
        result = sum;
        lastNode = now;
    }

    for (pair<int, int> ii : edge[now]) {
        if (!check[ii.first]) {
            check[now] = true;
            dfs(ii.first, sum + ii.second);
            check[now] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> V;
    for (int i = 0; i < V; i++) {
        int a, b, c;
        cin >> a;

        while (true) {
            cin >> b;

            if (b == -1) break;

            cin >> c;

            edge[a].push_back({ b, c });
        }
    }
    
    dfs(1, 0);
    dfs(lastNode, 0);

    cout << result << '\n';

    return 0;
}
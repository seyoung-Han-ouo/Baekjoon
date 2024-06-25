#include <iostream>
#include <vector>
using namespace std;

int n, result, lastNode;
vector<vector<pair<int, int>>> edge(10001);
bool check[10001];

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

    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        edge[a].push_back({ b, c });
        edge[b].push_back({ a, c });
    }
    
    dfs(1, 0);
    dfs(lastNode, 0);

    cout << result << '\n';

    return 0;
}
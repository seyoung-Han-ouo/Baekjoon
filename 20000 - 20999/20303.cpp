#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 30001

struct Steal {
    int cnt = 0;    // �ο� ��
    int candy = 0;  // ���� ��
};

int N, M, K;
int child[MAX];         // ���̵��� ���� ������ ��
bool visit[MAX];        // �湮 ����
int dp[MAX][3001];
vector<vector<int>> friends(MAX); // ģ�� ����
vector<Steal> steal;    // �� ������ �ο� ���� �� ���� ��

Steal bfs(int start);

// start�� ���Ե� ������ �ο� ���� ���� �� ���ϱ�
Steal bfs(int start) {
    queue<int> q;
    Steal ss = { 0, 0 };

    q.push(start);
    visit[start] = true;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        ss.cnt++;
        ss.candy += child[now];

        for (int n : friends[now]) {
            if (!visit[n]) {
                q.push(n);
                visit[n] = true;
            }
        }
    }

    return ss;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) cin >> child[i];

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    steal.push_back({ 0, 0 });
    for (int i = 1; i <= N; i++) {
        if (!visit[i]) steal.push_back(bfs(i));
    }

    // ���귯����  ���� �� �ִ� �ִ� ������ �� ���ϱ�
    for (int i = 1; i < steal.size(); i++) {
        int cnt = steal[i].cnt;
        int candy = steal[i].candy;

        for (int j = 0; j <= K; j++) {
            if (cnt > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j - cnt] + candy, dp[i - 1][j]);
        }
    }

    // ���
    cout << dp[steal.size() - 1][K - 1] << '\n';

    return 0;
}
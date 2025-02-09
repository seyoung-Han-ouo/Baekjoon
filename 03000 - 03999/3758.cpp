#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 101

struct Team {
    int id = 0;     // �� ID
    int score = 0;  // ȹ���� ����
    int cnt = 0;    // ���� Ƚ��
    int last = 0;   // ������ ���� �ð�
};

Team team[MAX];
int score[MAX][MAX];

void init();
bool compare(Team a, Team b);

// �迭 �ʱ�ȭ
void init() {
    for (int i = 0; i < MAX; i++) {
        team[i] = { i, 0, 0, 0 };

        for (int j = 0; j < MAX; j++) score[i][j] = 0;
    }
}

bool compare(Team a, Team b) {
    if (a.score == b.score) {
        if (a.cnt == b.cnt) return a.last < b.last;

        return a.cnt < b.cnt;
    }

    return a.score > b.score;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n, k, t, m;
        cin >> n >> k >> t >> m;

        init();

        for (int i = 0; i < m; i++) {
            int id, j, s;
            cin >> id >> j >> s;

            team[id].cnt++;
            team[id].last = i;
            score[id][j] = max(score[id][j], s);
        }

        // �� ���� ���� ���
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) 
                team[i].score += score[i][j];
        }

        sort(team + 1, team + n + 1, compare);

        // �츮 ���� ��� ã��
        for (int i = 1; i <= n; i++) {
            if (team[i].id == t) {
                cout << i << '\n';
                break;
            }
        }
    }

    return 0;
}
#include <iostream>
using namespace std;

struct Team {
    int cnt = 0;        // ������ ������ ��
    int scoreCnt = 0;   // ���� ���� �Ϸ��� ��
    int score = 0;      // ����
    int fifth = 0;      // �ټ���° ������ ����
};

int arr[1001];
Team team[201];

void teamsScore(int N);
int findWinner();
void init();

// �� ���� ���� ����ϱ�
void teamsScore(int N) {
    int num = 1;

    for (int i = 0; i < N; i++) {
        int now = arr[i];

        // ���� ���� ���ڰ� �������� ���� ��
        if (team[now].cnt < 6) continue;

        if (team[now].scoreCnt == 4) { // �ټ� ��° ������ ���� ���ϱ�
            team[now].scoreCnt++;
            team[now].fifth = num;
        }
        else if (team[now].scoreCnt < 4) { // ���� 4�� ������ �� ���ϱ�
            team[now].scoreCnt++;
            team[now].score += num;
        }

        num++;
    }
}

// �¸��� �� ã��
int findWinner() {
    int win = 0;

    for (int i = 1; i < 201; i++) {
        if (team[i].cnt < 6) continue;

        if (win == 0 || team[i].score < team[win].score) win = i;
        else if (team[i].score == team[win].score) // ������ ���� ���
            win = (team[i].fifth < team[win].fifth) ? i : win;
    }

    return win;
}

// �迭 �ʱ�ȭ
void init() {
    for (int i = 0; i < 201; i++) {
        arr[i] = 0;
        team[i] = { 0, 0, 0, 0 };
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            team[arr[i]].cnt++;
        }

        teamsScore(N);

        cout << findWinner() << '\n';

        init();
    }

    return 0;
}
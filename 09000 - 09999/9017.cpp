#include <iostream>
using namespace std;

struct Team {
    int cnt = 0;        // 참가한 주자의 수
    int scoreCnt = 0;   // 점수 집계 완료한 수
    int score = 0;      // 점수
    int fifth = 0;      // 다섯번째 선수의 점수
};

int arr[1001];
Team team[201];

void teamsScore(int N);
int findWinner();
void init();

// 각 팀의 점수 계산하기
void teamsScore(int N) {
    int num = 1;

    for (int i = 0; i < N; i++) {
        int now = arr[i];

        // 여섯 명의 주자가 참가하지 못한 팀
        if (team[now].cnt < 6) continue;

        if (team[now].scoreCnt == 4) { // 다섯 번째 주자의 점수 구하기
            team[now].scoreCnt++;
            team[now].fifth = num;
        }
        else if (team[now].scoreCnt < 4) { // 상위 4명 점수의 합 구하기
            team[now].scoreCnt++;
            team[now].score += num;
        }

        num++;
    }
}

// 승리한 팀 찾기
int findWinner() {
    int win = 0;

    for (int i = 1; i < 201; i++) {
        if (team[i].cnt < 6) continue;

        if (win == 0 || team[i].score < team[win].score) win = i;
        else if (team[i].score == team[win].score) // 점수가 같은 경우
            win = (team[i].fifth < team[win].fifth) ? i : win;
    }

    return win;
}

// 배열 초기화
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
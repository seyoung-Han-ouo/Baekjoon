#include <iostream>
using namespace std;

// 이름에 등장하는 알파벳의 개수
struct Love {
    int L = 0;
    int O = 0;
    int V = 0;
    int E = 0;
};

// 우승 확률 구하기
int probability(Love yeondu, string name) {
    Love team;

    team.L = yeondu.L;
    team.O = yeondu.O;
    team.V = yeondu.V;
    team.E = yeondu.E;

    // 연두의 이름과 팀명에 포함된 특정 알파벳들의 개수
    for (int i = 0; i < name.length(); i++) {
        if (name[i] == 'L') team.L++;
        if (name[i] == 'O') team.O++;
        if (name[i] == 'V') team.V++;
        if (name[i] == 'E') team.E++;
    }

    // 우승 확률 계산
    int num = ((team.L + team.O) * (team.L + team.V) * (team.L + team.E)
        * (team.O + team.V) * (team.O + team.E) * (team.V + team.E)) % 100;

    return num;
}

int main() {
    string yName;
    int N;

    Love yeondu;
    int big = -1; // 가장 높은 우승 확률
    string bigTeam = "0"; // 우승 확률이 가장 높은 팀의 이름

    // 입력
    cin >> yName;
    cin >> N;

    // 연두의 이름에 등장하는 알파벳들
    for (int j = 0; j < yName.length(); j++) {
        if (yName[j] == 'L') yeondu.L++;
        if (yName[j] == 'O') yeondu.O++;
        if (yName[j] == 'V') yeondu.V++;
        if (yName[j] == 'E') yeondu.E++;
    }

    // 각 팀의 우승 확률 구하기
    for (int i = 0; i < N; i++) {
        string tName;
        cin >> tName;

        int num = probability(yeondu, tName);

        // 가장 높은 우승 확률인지 확인하기
        if (big == -1 || num > big) {
            big = num;
            bigTeam = tName;
        }
        // 사전 순으로 가장 앞서는 팀 이름
        else if (num == big && tName < bigTeam)
            bigTeam = tName;
    }

    // 출력
    cout << bigTeam << endl;

    return 0;
}
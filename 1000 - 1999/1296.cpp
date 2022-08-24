#include <iostream>
using namespace std;

// �̸��� �����ϴ� ���ĺ��� ����
struct Love {
    int L = 0;
    int O = 0;
    int V = 0;
    int E = 0;
};

// ��� Ȯ�� ���ϱ�
int probability(Love yeondu, string name) {
    Love team;

    team.L = yeondu.L;
    team.O = yeondu.O;
    team.V = yeondu.V;
    team.E = yeondu.E;

    // ������ �̸��� ���� ���Ե� Ư�� ���ĺ����� ����
    for (int i = 0; i < name.length(); i++) {
        if (name[i] == 'L') team.L++;
        if (name[i] == 'O') team.O++;
        if (name[i] == 'V') team.V++;
        if (name[i] == 'E') team.E++;
    }

    // ��� Ȯ�� ���
    int num = ((team.L + team.O) * (team.L + team.V) * (team.L + team.E)
        * (team.O + team.V) * (team.O + team.E) * (team.V + team.E)) % 100;

    return num;
}

int main() {
    string yName;
    int N;

    Love yeondu;
    int big = -1; // ���� ���� ��� Ȯ��
    string bigTeam = "0"; // ��� Ȯ���� ���� ���� ���� �̸�

    // �Է�
    cin >> yName;
    cin >> N;

    // ������ �̸��� �����ϴ� ���ĺ���
    for (int j = 0; j < yName.length(); j++) {
        if (yName[j] == 'L') yeondu.L++;
        if (yName[j] == 'O') yeondu.O++;
        if (yName[j] == 'V') yeondu.V++;
        if (yName[j] == 'E') yeondu.E++;
    }

    // �� ���� ��� Ȯ�� ���ϱ�
    for (int i = 0; i < N; i++) {
        string tName;
        cin >> tName;

        int num = probability(yeondu, tName);

        // ���� ���� ��� Ȯ������ Ȯ���ϱ�
        if (big == -1 || num > big) {
            big = num;
            bigTeam = tName;
        }
        // ���� ������ ���� �ռ��� �� �̸�
        else if (num == big && tName < bigTeam)
            bigTeam = tName;
    }

    // ���
    cout << bigTeam << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct coordinate {
    int idx1; // �Է��� �� �ε���
    int idx2; // ������ �� �ε���
    int x;
};

// ��������
bool compare1(coordinate &a, coordinate &b) {
    return a.x < b.x;
}

// ������ ������� ������
bool compare2(coordinate& a, coordinate& b) {
    return a.idx1 < b.idx1;
}

int main() {
	int N;
	cin >> N;

	vector<coordinate> x(N);

    // �Է�
    for (int i = 0; i < N; i++) {
        cin >> x[i].x;
        x[i].idx1 = i;
    }  

    // ����
    sort(x.begin(), x.end(), compare1);

    // ���� ���� ���� ã��
    int count = 0;
    x[0].idx2 = 0;
    for (int i = 1; i < N; i++) {
        if(x[i].x == x[i - 1].x)
            x[i].idx2 = count;
        else {
            count++;
            x[i].idx2 = count;
        }
    }

    // ������ ������� ������
    sort(x.begin(), x.end(), compare2);

    // ���
    for (int i = 0; i < N; i++)
        cout << x[i].idx2 << " ";

	return 0;
}
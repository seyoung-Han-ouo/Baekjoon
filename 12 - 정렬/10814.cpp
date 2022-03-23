#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct member {
    int age = 0;
    string name;
};

// ���̰� �����ϴ� ������
bool compare(member a, member b) {
    return a.age < b.age;
}

int main() {
	int N;
	cin >> N;

	vector<member> mb(N);

    // �Է�
    for (int i = 0; i < N; i++)
        cin >> mb[i].age >> mb[i].name;

    // ����
    stable_sort(mb.begin(), mb.end(), compare);

    // ���
    for (int i = 0; i < N; i++)
        cout << mb[i].age << " " << mb[i].name << "\n";

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct member {
    int age = 0;
    string name;
};

// 나이가 증가하는 순으로
bool compare(member a, member b) {
    return a.age < b.age;
}

int main() {
	int N;
	cin >> N;

	vector<member> mb(N);

    // 입력
    for (int i = 0; i < N; i++)
        cin >> mb[i].age >> mb[i].name;

    // 정렬
    stable_sort(mb.begin(), mb.end(), compare);

    // 출력
    for (int i = 0; i < N; i++)
        cout << mb[i].age << " " << mb[i].name << "\n";

	return 0;
}
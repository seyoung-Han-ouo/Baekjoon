#include <iostream>
using namespace std;

void findSolo(int* oneTwo, int third);

// �� �� �� ȥ�� ��ǥ�� �ٸ� ���� ã�´�.
void findSolo (int* oneTwo, int third) {
	int solo;

	if (oneTwo[0] == oneTwo[1]) // ù��°�� �ι�° ���� ��ǥ�� ����
		solo = third;
	else if (third == oneTwo[0]) // ù��°�� ����°�� ����
		solo = oneTwo[1];
	else // �ι�°�� ����°�� ����
		solo = oneTwo[0];

	cout << solo << " ";
}

int main() {
	// �� 2���� ��ġ ������ �迭�� �����Ѵ�.
	int xNum[2], yNum[2];
	for (int i = 0; i < 2; i++)
		cin >> xNum[i] >> yNum[i];

	// ������ �� 1���� ��ġ ����
	int x, y;
	cin >> x >> y;

	findSolo(xNum, x);
	findSolo(yNum, y);
	
	return 0;
}
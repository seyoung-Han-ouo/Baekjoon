#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int layer = 1; //1�� 1��, 2 ~ 7�� 2��... �� ���� �� ���� 6�� ����� �þ��.
	int layerNum = 1;

	if (N != 1){
		while (true) {
			// N�� layerNum���� �����Ƿ� �ش� layer�� ��ġ�� �����̴�.
			if (N <= layerNum) break;

			// N�� layerNum���� ���� ���� ��
			layerNum += 6 * layer++;
		}
	}
	cout << layer; // ���۰� ���� ��� �����ϱ� ������ 1�� ���Ѵ�.

	return 0;
}
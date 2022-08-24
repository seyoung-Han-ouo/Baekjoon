#include <iostream>
using namespace std;

int main() {
    int N; // ��ȣ�� ���� �޿� �̿��� ��ȭ�� ����
    cin >> N;

    // �ݾ� û�� �����Ǵ� �ð�
    int yCount = 0, mCount = 0;
    for (int i = 0; i < N; i++) {
        int M;
        cin >> M;

        yCount += (M / 30) + 1;
        mCount += (M / 60) + 1;
    }

    // �� ������� û�� �ݾ�
    int yCost = yCount * 10;
    int mCost = mCount * 15;

    // ���
    if (yCost < mCost)
        printf("Y %d\n", yCost);
    else if (yCost == mCost)
        printf("Y M %d\n", yCost);
    else
        printf("M %d", mCost);

    return 0;
}
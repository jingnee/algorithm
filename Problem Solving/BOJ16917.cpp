// ��� �� �Ķ��̵� ��
#include <iostream>
using namespace std;

int main() {
	//���ġŲ X����, �Ķ��̵� ġŲ Y����
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int min = 100000;
	if (A + B <= 2 * C) {		//���ġŲ+�Ķ��̵�ġŲ ���� <= �ݹݰ��� �̸� �׳� ����Ķ��̵尹���״�λ�
		cout << X*A + Y*B;
	}
	else {
		min = (X < Y ) ? X:Y;
		X -= min;
		Y -= min;

		if (X >= Y && A >= 2*C) 
			cout << 2 * C*min + 2*C*X;

		else if(X < Y && B >= 2*C)
			cout << 2 * C*min + 2*C*Y;

		else
		cout << 2 * C*min + A*X + B*Y;
	}
	return 0;
}
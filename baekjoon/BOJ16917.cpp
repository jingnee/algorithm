// 양념 반 후라이드 반
#include <iostream>
using namespace std;

int main() {
	//양념치킨 X마리, 후라이드 치킨 Y마리
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int min = 100000;
	if (A + B <= 2 * C) {		//양념치킨+후라이드치킨 가격 <= 반반가격 이면 그냥 양념후라이드갯수그대로사
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
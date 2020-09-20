//Hay For Sale
#include <iostream>
#include <algorithm>
using namespace std;

int hay[50001], answer[50001];
int C, H;


int main() {
	cin >> C >> H;
	for (int i = 0; i < H; i++)cin >> hay[i];
	
	for (int i = 0; i < H; i++) {
		for (int j = C; j >= hay[i]; j--) {
			answer[j] = max(answer[j], answer[j - hay[i]] + hay[i]);
		}
	}
	cout << answer[C];
}

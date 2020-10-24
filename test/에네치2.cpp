#include <iostream>
#include <sstream>

using namespace std;

int blocks[2][6] = { { 6,2,11,0,3,5 },{ 6,3,0,9,0,5 } };
int bricks[100];
int ans;

void solution(int day, int width) {
	for (int i = 0; i < day; i++) {
		for (int j = 0; j < width; j++) {
			bricks[j] += blocks[i][j];
		}
		//왼쪽에서 판단
		int left = 0;
		for (int l = 1; l < width; l++) {
			if (bricks[left] <= bricks[l]) {
				for (int k = left+1; k < l; k++) {
					ans += bricks[left] - bricks[k];
					bricks[k] = bricks[left];
				}
				left = l;
			}
		}

		//오른쪽에서 판단
		int right = width-1;
		for (int r = width-2; r >= 0; r--) {
			if (bricks[right] <= bricks[r]) {
				for (int k = right - 1; k > r; k--) {
					ans += bricks[right] - bricks[k];
					bricks[k] = bricks[right];
				}
				right = r;
			}
		}
	}
	cout << ans;
}

int main() {
	
	solution(2, 6);
}

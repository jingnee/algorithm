/*함께 블록 쌓기*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

int N, M, H;
vector<int> block[50];
int DP[1001];
int now_add[1001];

int main() {
	cin >> N >> M >> H;
	cin.get();
	for (int i = 0; i < N; i++) {
		stringstream stream;
		string str;
		int num;
		getline(cin, str);				//공백포함한 문자열 입력받기
		stream.str(str);
		while (stream >> num)block[i].push_back(num);
	}

	for (int i = 0; i < N; i++) sort(block[i].begin(), block[i].end());

	for (int i = 0; i < N; i++) {
		memset(now_add, 0, sizeof(now_add));
			for (int j = 0; j < block[i].size(); j++) {
				int num = block[i][j];
				now_add[num]++;
				for (int k = 1; k <= H; k++) {
					if (k + num > H) break;
					now_add[num + k] += DP[k];
			}
		}
			for (int j = 1; j <= H; j++) {
				DP[j] += now_add[j];
				DP[j] %= 10007;
			}
	}

	cout << DP[H] << "\n";
}
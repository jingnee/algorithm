/*Ãß¿ù*/
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

vector<string> In;
vector<string> Out;
int carNum[1000];
int visit[1000];
int N, answer;
int nextIndex(int idx) {
	if (!visit[idx])return idx;
	else return nextIndex(idx + 1);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		In.push_back(str);
	}
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		Out.push_back(str);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[j] && In[j]==Out[i]) {
				carNum[i] = j;
				visit[j] = true;
			}
		}
	}

	memset(visit, 0, sizeof(visit));
	int index = 0;
	for (int i = 0; i < N; i++) {
		index = nextIndex(index);
		if (carNum[i] != index) {
			answer++;
		}
		visit[carNum[i]] = true;
	}

	cout << answer << "\n";
}
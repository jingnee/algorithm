//성냥개비
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int T, N;
long long minMatches[101];

string getMax() {
	string ret = "";
	for (int i = 0; i < N / 2; i++)ret += "1";
	if (N % 2 == 1)ret[0] = '7';
	return ret;
}

void setMin() {
	minMatches[2] = 1;
	minMatches[3] = 7;
	minMatches[4] = 4;
	minMatches[5] = 2;
	minMatches[6] = 6;
	minMatches[7] = 8;
	minMatches[8] = 10;
	string add[8] = { "","","1","7","4","2","0","8" };

	for (int i = 9; i <= 100; i++) {
		for (int j = 2; j <= 7; j++) {
			string str = to_string(minMatches[i - j]) + add[j];
			if (minMatches[i] == 0)minMatches[i] = stoll(str);
			else minMatches[i] = (minMatches[i] > stoll(str)) ? stoll(str) : minMatches[i];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	setMin();

	for (int test_case = 0; test_case < T; test_case++) {
		cin >> N;
		cout << minMatches[N] << " " << getMax() << "\n";
	}

}

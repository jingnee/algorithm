#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int people[26];
int taggerNum[26];
map<int, bool> fast;
int last;

void solution(int numOfAllPlayers, int numOfQuickPlayers, char *namesOfQuickPlayers, int numOfGames, int *numOfMovesPerGame) {
	//A는 항상 먼저 술래
	taggerNum[0]++;
	int tagger = 0;
	for (int i = 0; i<numOfAllPlayers-1; i++)people[i] = i + 1;
	for (int i = 0; i<numOfQuickPlayers; i++)fast[namesOfQuickPlayers[i]-65] = true;

	for (int i = 0; i<numOfGames; i++) {
		int m = numOfMovesPerGame[i];
		if (m>0)last = (last + m) % (numOfAllPlayers - 1);
		else {
			last += m;
			if (last<0) last = numOfAllPlayers + last - 1;
		}

		//수건 놓은 위치가 발 빠른 애들인 경우
		if (fast[people[last]]) {
			//기존 술래가 한번 더 술래
			taggerNum[tagger]++;
		}
		else {
			taggerNum[people[last]]++;
			int temp = tagger;
			tagger = people[last];
			people[last] = temp;
		}
	}

	for (int i = 0; i<numOfAllPlayers-1; i++) {
		cout << (char)(people[i] + 'A') << " " << taggerNum[people[i]] << "\n";
	}
	cout << (char)(tagger + 'A') << " " << taggerNum[tagger] << "\n";
}

int main() {
	char quick[] = { 'B', 'D', 'I', 'M', 'P' };
	int game[] = { 3, -4, 5, 6, -7, -8, 10, -12, -15, -20, 23 };

	solution(17, 5, quick, 11, game);
}

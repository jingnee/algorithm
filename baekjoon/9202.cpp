//Boggle
#include <iostream>
#include <string>
#include <cstring>
#include <set>
using namespace std;

int w, b, score, hit;
char board[5][5];
bool visit[5][5];
int dr[8] = { -1,-1,-1,0,1,1,1,0 };
int dc[8] = { -1,0,1,1,1,0,-1,-1 };
int count_score[9] = { 0,0,0,1,1,2,3,5,11 };
string longest;
set<string> words;

class Trie {
private:
	bool finish;
	Trie *Node[26];
public:
	//생성자
	Trie() {
		finish = false;
		for (int i = 0; i < 26; i++)Node[i] = NULL;
	}
	//소멸자
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (Node[i] != NULL)
				delete Node[i];
	}
	//문자열 삽입
	void insert(string str) {
		Trie *trie = this;
		for (int i = 0; i < str.size(); i++) {
			int cur = str[i] - 'A';
			if (!trie->Node[cur])
				trie->Node[cur] = new Trie();
			trie = trie->Node[cur];
		}
		trie->finish = true;
	}
	//문자열 찾기
	int find(string str) {
		Trie *trie = this;
		for (int i = 0; i < str.size(); i++) {
			int cur = str[i] - 'A';
			//더 찾아보지 않아도 됨
			if (!trie->Node[cur])return -1;
			trie = trie->Node[cur];
		}
		//찾음
		if (trie->finish)return 1;
		//마지막만 아닐뿐 단어는 순서대로 존재
		else return 0;
	}
};

void DFS(int r, int c, int length, Trie *trie, string str) {
	visit[r][c] = true;
	if (length > 8)return;

	if (trie->find(str) == 1 && words.find(str) == words.end()) {
		words.insert(str);
		hit++;
		if (longest.size() <= str.size()) {
			if (longest.size() < str.size()) longest = str;
			else if (longest > str)longest = str;
		}
		score += count_score[str.size()];
	}

	for (int d = 0; d < 8; d++) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (nr < 0 || nc < 0 || nr >= 4 || nc >= 4 || visit[nr][nc])continue;
		if (trie->find(str + board[nr][nc]) != -1) {
			int idx = board[nr][nc] - 'A';
			//visit[nr][nc] = true;
			DFS(nr, nc, length + 1, trie, str + board[nr][nc]);
			visit[nr][nc] = false;
		}
	}
	visit[r][c] = false;
}

int main() {
	Trie *Root = new Trie();

	cin >> w;
	for (int i = 0; i < w; i++) {
		string str;
		cin >> str;
		Root->insert(str);
	}
	
	cin >> b;
	for (int i = 0; i < b; i++) {
		//board 입력
		for (int j = 0; j < 4; j++)
				cin >> board[j];
		
		for (int r = 0; r < 4; r++) {
			for (int c = 0; c < 4; c++) {
				string str = "";
				str += board[r][c];
				int idx = board[r][c] - 'A';
				if (Root->find(str) != -1) {
					visit[r][c] = true;
					DFS(r, c, 1, Root, str);
					visit[r][c] = false;
				}
			}
		}
		cout << score << " " << longest << " " << hit << "\n";
		score = hit = 0;
		longest = "";
		words.clear();
		memset(visit, false, sizeof(visit));
	}
}

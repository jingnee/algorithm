/*단어 변환*/
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

string begine, target;
vector<string> words;
queue<string> que;
bool visit[50];
int first;

bool possible(string a, string b) {
	int find = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i])find++;
	}
	if (find == 1)return true;
	else return false;
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	que.push(begin);

	if (first == 0) {
		bool flag = false;
		for (int i = 0; i < words.size(); i++) {
			if (target == words[i])flag = true;
		}
		if (!flag)return 0;
		first++;
	}

	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; i++) {
			string temp = que.front();
			que.pop();
			//temp와 한글자 차이인애 찾기
			for (int j = 0; j < words.size(); j++) {
				//방문한 애는 넘겨
				if (visit[j])continue;
				//안되는 애도 넘겨
				if (!possible(temp, words[j]))continue;
				visit[j] = true;
				que.push(words[j]);
				if (words[j] == target) {
					return answer + 1;
				}
			}
		}
		answer++;
	}
	return 0;
}

int main() {
	begine = "hit";
	target = "hhh";
	//words = { "hot","dot", "dog", "lot", "log","cog"};
	words = { "hhh","hht" };

	cout<< solution(begine, target, words) << "\n";
}

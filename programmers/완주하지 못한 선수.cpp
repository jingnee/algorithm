//완주하지 못한 선수
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;
map<string, int> m;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	for (auto a : completion)m[a]++;
	for (auto a : participant) {
		if (m[a] == 0) {
			answer = a;
			break;
		}
		m[a]--;
	}		
	return answer;
}

int main() {
	cout << solution({ "mislav", "stanko", "mislav", "ana" }, { "stanko", "ana", "mislav" });
}

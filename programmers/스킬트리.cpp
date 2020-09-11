#include <string>
#include <vector>

using namespace std;
char ch;
char alph[26];

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
	int num = 0;
	for (int i = 0; i<skill.length(); i++)
		alph[skill[i] - 65]++;
	ch = skill[num++];

	for (int i = 0; i < skill_trees.size(); i++) {
		for (int j = 0; j <= skill_trees[i].length(); j++) {
			char temp = skill_trees[i][j];
			if (j == skill_trees[i].length())answer++;
			else if (alph[temp - 65] == 0) continue;
			else if (temp != ch) break;
			else if (temp == ch) 
				ch = skill[num++];
		}
		num = 0;
		ch = skill[num++];
	}

    return answer;
}

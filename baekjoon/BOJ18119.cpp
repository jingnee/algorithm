/*단어 암기*/
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int N, M;
vector<set<char>> v;
int alphabets[10000][26];
int temp[10000][26];
int alpha_size[10000];
int temp_size[10000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			int idx = str[j] - 'a';
			alphabets[i][idx] = 1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 26; j++) {
			temp[i][j] = alphabets[i][j];
			if (temp[i][j] == 1) {
				alpha_size[i]++;
				temp_size[i]++;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		int num, cnt = 0;
		char ch;
		cin >> num >> ch;
		for (int j = 0; j < N; j++) {
			//단어 잊어버림
			if (num == 1) {
				//그 단어에 알파벳이 있으면
				if (temp[j][ch - 'a']) {
					temp[j][ch - 'a']--;
					temp_size[j]--;
				}
				//그 단어에 알파벳이 없으면 사이즈같으면 ++
				else
					if (temp_size[j] == alpha_size[j])cnt++;
					
			}
			//단어 기억함
			else {
				//기존 단어에 그 알파벳 있었으면
				if (alphabets[j][ch-'a']) {
					//임시에 알파벳 추가하고
					temp[j][ch - 'a']++;
					temp_size[j]++;
					//추가한 후에 사이즈 같으면 다기억하는거니까 cnt++
					if (temp_size[j] == alpha_size[j])cnt++;
				}
				//기존단어에 그 알파벳 없었으면 사이즈비교해서 같으면 cnt++ 아니면 몰라
				else 
					if (temp_size[j] == alpha_size[j])cnt++;
			}
		}
		cout << cnt << "\n";
	}
}

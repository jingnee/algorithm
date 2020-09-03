#include <iostream>
#include <string>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> &key) {
	vector<vector<int>> vec = key;
	int size = vec.size();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			vec[j][size-i-1] = key[i][j];
		}
	}
	key = vec;
}

bool matchKey(vector<vector<int>> key, vector<vector<int>> newLock, int r, int c) {
	//[r][c]위치에서부터 key 더하기
	for (int i = r; i < key.size()+r; i++) {
		for (int j = c; j < key.size()+c; j++) {
			newLock[i][j] += key[i - r][j - c];
		}
	}

	//map위치 확인
	for (int i = key.size() - 1; i <= newLock.size() - key.size(); i++) {
		for (int j = key.size() - 1; j <= newLock.size() - key.size(); j++) {
			if (newLock[i][j] != 1)return false;
		}
	}
	return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	int newSize = lock.size() + (key.size() - 1) * 2;
	vector<vector<int>> newLock(newSize, vector<int>(newSize, 0));

	for (int i = key.size() - 1; i < key.size() + lock.size()-1; i++) {
		for (int j = key.size() - 1; j < key.size() + lock.size()-1; j++) {
			newLock[i][j] = lock[i - key.size() + 1][j - key.size() + 1];
		}
	}

	for (int ro = 0; ro < 4; ro++) {
		for (int i = 0; i <= newSize-key.size(); i++) {
			for (int j = 0; j <= newSize-key.size(); j++) {
				if (matchKey(key, newLock, i, j))return true;
			}
		}
		rotate(key);
	}

	return false;
}

int main() {
	cout << solution({{0, 0, 0}, {1, 0, 0}, {0, 1, 1}}, {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}});
}

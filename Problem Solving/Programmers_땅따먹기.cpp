/*땅따먹기*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land) {

	for (int i = 1; i < land.size(); i++) {
		land[i][0] += max({ land[i - 1][1], land[i - 1][2], land[i - 1][3] });
		land[i][1] += max({ land[i - 1][0], land[i - 1][2], land[i - 1][3] });
		land[i][2] += max({ land[i - 1][0], land[i - 1][1], land[i - 1][3] });
		land[i][3] += max({ land[i - 1][0], land[i - 1][1], land[i - 1][2] });
	}

	return max({land[land.size()-1][0],land[land.size() - 1][1] ,land[land.size() - 1][2] ,land[land.size() - 1][3] });
}

int main() {
	vector<vector<int>> land;
	land = { {1,2,3,5},{5,6,7,8},{4,3,2,1} };

	cout << solution(land);
}

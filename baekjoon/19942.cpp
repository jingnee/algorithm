//다이어트
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct nutrient {
	nutrient(int p, int f, int c, int v, int pr) : protein(p), fat(f), carbo(c), vitamin(v), price(pr) {}

	int protein = 0;
	int fat = 0;
	int carbo = 0;
	int vitamin = 0;
	int price = 0;
};

int order[15];
int ret[15] = { 16, };
int N, answer = 1e9;
int max_p, max_f, max_c, max_v;
vector<nutrient> nutrients;

bool isFirst(int n) {
	for (int i = 0; i < n; i++) {
		if (ret[i] > order[i])return true;
		else if(ret[i]<order[i])return false;
	}
	return true;
}
void DFS(int idx, int cnt, int n, int sum_p, int sum_f, int sum_c, int sum_v, int sum_price) {
	if (sum_p >= max_p && sum_f >= max_f && sum_c >= max_c && sum_v >= max_v) {
		if (answer > sum_price || (answer == sum_price && isFirst(n))) {
			for (int i = 0; i < n; i++)ret[i] = order[i];
			for (int i = n; i < N; i++)ret[i] = 0;
			answer = sum_price;
		}
	}
	if (cnt == n)return;
	for (int i = idx; i < N; i++) {
		order[cnt] = i+1;
		DFS(i + 1, cnt + 1, n, sum_p + nutrients[i].protein, sum_f + nutrients[i].fat, sum_c + nutrients[i].carbo, sum_v + nutrients[i].vitamin, sum_price + nutrients[i].price);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	cin >> max_p >> max_f >> max_c >> max_v;
	for (int i = 0; i < N; i++) {
		int p, f, c, v, pr;
		cin >> p >> f >> c >> v >> pr;
		nutrients.push_back(nutrient(p, f, c, v, pr));
	}
	for (int i = 1; i <= N; i++) {
		DFS(0, 0, i, 0, 0, 0, 0, 0);
		for (int j = 0; j < i; j++)order[j] = 0;
	}

	int idx = 0;
	if (answer == 1e9)cout << "-1\n";
	else {
		cout << answer << "\n";
		while (idx < N && ret[idx] != 0)cout << ret[idx++] << " ";
	}
}
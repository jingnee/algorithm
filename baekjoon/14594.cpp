//동방 프로젝트(small)
#include <iostream>
using namespace std;

int parent[101];
bool check[101];
int N, M, ans;

int getParent(int x) {
	if (parent[x] == x)return x;
	else return parent[x] = getParent(parent[x]);
}

void Union(int a, int b) {
	a = parent[a];
	b = parent[b];

	if (a < b)parent[b] = a;
	else parent[a] = b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)parent[i] = i;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		while (getParent(a) != getParent(b)) {
			Union(a, b);
			b--;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (!check[parent[i]]) {
			check[parent[i]] = true;
			ans++;
		}
	}
	cout << ans;
}

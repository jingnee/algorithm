/*공항*/
#include <iostream>
using namespace std;

int G, P, ans;
int parent[100001];

int getParent(int x) {
	if (parent[x] == x)return x;
	else return parent[x] = getParent(parent[x]);
}

void Union(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	parent[a] = b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> G >> P;
	for (int i = 1; i <= G; i++)parent[i] = i;
	for (int i = 0; i < P; i++) {
		int g;
		cin >> g;
		int doking = getParent(g);
		if (doking != 0) {		//도킹할 수 있으면
			ans++;
			Union(doking, doking - 1);
		}
		else break;
	}
	cout << ans;
}

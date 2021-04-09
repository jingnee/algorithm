//π∞≈Î
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

bool visit[201][201];
queue < pair<pair<int, int>, int>> que;
set<int> answer;
int A, B, C;

void bfs() {
	que.push({ { 0,0 },C });
	while (!que.empty()) {
		int a = que.front().first.first;
		int b = que.front().first.second;
		int c = que.front().second;
		que.pop();

		if (visit[a][b])continue;
		visit[a][b] = true;
		if (a == 0)answer.insert(c);

		if (A - a >= c)
			que.push({ {a + c,b},0 });
		else
			que.push({ {A, b}, c + a - A });

		if (B - b >= c)
			que.push({ {a, b + c}, 0 });
		else
			que.push({ {a, B}, c + b - B });

		if (A - a >= b)
			que.push({ {a + b, 0}, c });
		else
			que.push({ {A, b + a - A}, c });

		if (C - c >= b)
			que.push({ {a, 0}, c + b });
		else
			que.push({ {a, b + c - C}, C });

		if (B - b >= a)
			que.push({ {0, b + a}, c });
		else
			que.push({ {a + b - B, B}, c });

		if (C - c >= a)
			que.push({ {0, b}, c + a });
		else
			que.push({ {a + c - C, b}, C });
	}
	//if (!visit[min((a + b), B)][c]) dfs(max(a + b - B, 0), min(a + b, B), c);
}

int main() {
	cin >> A >> B >> C;
	bfs();
	
	for (auto s : answer)cout << s << " ";
}
/*트리*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[51];
int N, root, del, answer;

void DFS(int cur) {
	if (cur == del)return;
	//자식 노드가 없을 경우
	if (tree[cur].size() == 0) {
		answer++;
		return;
	}
	//자식 노드가 한개인데 삭제해야할 노드일 경우
	else if (tree[cur].size() == 1 && tree[cur][0] == del) answer++;

	else{
		for (int i = 0; i < tree[cur].size(); i++) {
			DFS(tree[cur][i]);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if(a!=-1) tree[a].push_back(i);
		else root = i;
	}
	cin >> del;
	DFS(root);
	cout << answer << "\n";
}
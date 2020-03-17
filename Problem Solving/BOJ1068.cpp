/*Ʈ��*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[51];
int N, root, del, answer;

void DFS(int cur) {
	if (cur == del)return;
	//�ڽ� ��尡 ���� ���
	if (tree[cur].size() == 0) {
		answer++;
		return;
	}
	//�ڽ� ��尡 �Ѱ��ε� �����ؾ��� ����� ���
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
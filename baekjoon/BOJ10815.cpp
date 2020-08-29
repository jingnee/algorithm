#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int binary_search(int x, int* arr) {
	int left = 0;
	int right = n;
	int mid = 0;
	while (left <= right) {
		mid = (left + right) / 2;

		if (arr[mid] == x)return 1;
		else if (arr[mid] < x) left = mid + 1;
		else if (arr[mid] > x) right = mid - 1;
	}
	return 0;
}
int main() {
	cin >> n;
	int *sangeun = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> sangeun[i];
	}
	cin >> m;
	int *card = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> card[i];
	}

	sort(sangeun, sangeun + n);

	for (int i = 0; i < m; i++) {
		cout << binary_search(card[i], sangeun) <<" ";
	}cout << endl;
}

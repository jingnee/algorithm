/*ÃÖ´ñ°ª*/
#include<iostream>
using namespace std;

int main() {
	int number[9];
	for (int i = 0; i < 9; i++) 	cin >> number[i];
	
	int maxNum = number[0];
	int index = 0;
	for (int i = 1; i < 9; i++) {
		if (maxNum < number[i]) {
			maxNum = number[i];
			index = i;
		}
	}
	cout << maxNum << "\n" << index+1 << "\n";
}
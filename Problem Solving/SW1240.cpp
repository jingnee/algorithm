//�ܼ� 2�� ��ȣ�ڵ�
/*
��ȣ�ڵ�� 8���� ���ڷ� ����, �� ���ڴ� 7���� �������� ����
1. ��ü �ʿ��� ��ȣ�ڵ��� �κ�ã��(���ٸ� ã���� ��)
2. ��ȣ�ڵ� ù�� �ε����� si,sj�� �����ؼ� sj�� 8�� �����ϸ鼭 Ž��
3. code�迭�� 7���� �������� �̷���� ��ȣ�ڵ带 �ְ�, code�迭�� �̿��ؼ� ���� ����
	code�迭�� 1���� ����
*/
#include<iostream>
using namespace std;

int N, M;			//N:����, M:����
//char num[10][56] = {
//	{0,0,0,1,1,0,1},		//0
//  {0,0,0,1,0,1,1},		//9
//------------------------------
//	{0,0,1,1,0,0,1},		//1
//	{0,0,1,0,0,1,1},		//2
//-------------------------------
//	{0,1,0,0,0,1,1},		//4
//	{0,1,0,1,1,1,1},		//6
//-------------------------------
//	{0,1,1,1,1,0,1},		//3
//	{0,1,1,1,0,1,1},		//7
//-------------------------------
//	{0,1,1,0,0,0,1},		//5
//	{0,1,1,0,1,1,1},		//8

//};
int map[50][100];
int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int code[9];				//���� ��ȣ�ڵ带 int�� ��ȯ�� ����
		int mini_j = 0, flag = 0;
		int si = 0, sj = 0;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {					//��ü ��ȣ�ڵ� �Է¹ޱ�
			for (int j = 0; j < M; j++) {
				//cin >> map[i][j];
				scanf("%1d", &map[i][j]);
				if (map[i][j] == 1 && flag == 0) {		//1�̳��������� �߽����� ��ȣ�ڵ�ã��
					si = i;
					mini_j = j;
					
				}
			}
		}

		for (int j = mini_j + 55; j >= mini_j; j--) {
			if (map[si][j] == 1) {//�ڿ������� �������� 1�� ó�������� ���� ��ȣ�ڵ��� ���� �������ڸ�
				sj = j - 55;
				break;
			}
		}
		//cout << "��ȣ�ڵ� ������ġ [" << si << "][" << sj << "]" << endl;
		//��ȣ�ڵ�� map[si][sj]���� map[si+?][sj+55]�̴�.
		int index = 1;
		for (int j = sj; j < sj + 56; j += 7) {
			int start = j;
			if (map[si][start + 1] == 0) {		//0,1,2,9
				if (map[si][start + 2] == 0) {		//0,9
					if (map[si][start + 4] == 1) code[index++] = 0;	//0
					else code[index++] = 9;		//9
				}
				else {			//1,2
					if (map[si][start + 3] == 1) code[index++] = 1;//1
					else code[index++] = 2;
				}
			}
			else if (map[si][start + 1] == 1) {	//3,4,5,6,7,8
				if (map[si][start + 2] == 0) {		//4,6
					if (map[si][start + 3] == 1) code[index++] = 6;
					else code[index++] = 4;
				}
				else {			//3,5,7,8
					if (map[si][start + 3] == 0) {		//5,8
						if (map[si][start + 4] == 0) code[index++] = 5;
						else code[index++] = 8;
					}
					else {		//3,7
						if (map[si][start + 4] == 0) code[index++] = 7;
						else code[index++] = 3;
					}
				}
			}
		}

	/*	for (int i = 1; i <= 8; i++)cout << code[i] << ' ';
		cout << endl;*/

		int result = 0;
		int answer = 0;
		answer = code[1] + code[2] + code[3] + code[4] + code[5] + code[6] + code[7] + code[8];
		result = (code[1] + code[3] + code[5] + code[7]) * 3 + code[2] + code[4] + code[6] + code[8];
		//cout << "result: " << result << endl;
		if (result % 10 != 0) answer = 0;

		cout << "#" << test_case << ' ' << answer << endl;
	}
}
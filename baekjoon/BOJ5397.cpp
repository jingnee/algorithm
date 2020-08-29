/*Ű�ΰ� --stack �̿�*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		stack<char>password;			//ó�� ��й�ȣ ���� ����
		stack<char>temp;				//<������ �־��� ����
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '<') {			//������ ������ �־�����ϴϱ� �ֱٰ��� temp�� �־���
				if (!password.empty()) {
					char c = password.top();
					password.pop();
					temp.push(c);
				}
			}
			else if (str[i] == '>'){		//���������� �̵��ؾ��ϴϱ� temp�� ������ ���� password�� �־���
				if (!temp.empty()) {
					char c = temp.top();
					temp.pop();
					password.push(c);
				}
			}
			else if (str[i] == '-') {		//����°Ŵϱ� password.pop()����
				if (!password.empty())password.pop();
			}
			else {							//�Ϲݹ��ڴ� ������ push
				password.push(str[i]);
			}
		}
		while (!temp.empty()) {				//temp�� ������ �� ��� password�� �־���
			char c = temp.top();
			temp.pop();
			password.push(c);
		}
		stack<char>answer;
		while (!password.empty()) {    //stack�� �Ųٷ� ��µǴϱ� ���ο� answer��� stack�� ���� answer�� top���� ���
			answer.push(password.top());
			password.pop();
		}
		int n = answer.size();
		for (int i = 0; i < n; i++) {
			cout << answer.top();
			answer.pop();
		}cout << endl;
	}
}
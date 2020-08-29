/*키로거 --stack 이용*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		stack<char>password;			//처음 비밀번호 담을 스택
		stack<char>temp;				//<만나면 넣어줄 스택
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '<') {			//이전값 다음에 넣어줘야하니까 최근값을 temp에 넣어줌
				if (!password.empty()) {
					char c = password.top();
					password.pop();
					temp.push(c);
				}
			}
			else if (str[i] == '>'){		//다음값으로 이동해야하니까 temp로 빼놓은 값을 password에 넣어줌
				if (!temp.empty()) {
					char c = temp.top();
					temp.pop();
					password.push(c);
				}
			}
			else if (str[i] == '-') {		//지우는거니까 password.pop()해줌
				if (!password.empty())password.pop();
			}
			else {							//일반문자는 무조건 push
				password.push(str[i]);
			}
		}
		while (!temp.empty()) {				//temp에 빼놓은 값 모두 password에 넣어줌
			char c = temp.top();
			temp.pop();
			password.push(c);
		}
		stack<char>answer;
		while (!password.empty()) {    //stack은 거꾸로 출력되니까 새로운 answer라는 stack을 만들어서 answer을 top부터 출력
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
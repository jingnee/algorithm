#include <string>
#include <vector>

using namespace std;

 int solution(vector<int> priorities, int location) {
	int answer = 1;
	int end = priorities.size();
	while(end >= 0) {
		int i = 0;
		int j = i + 1;
		for (j; j < end; j++) {
			if (priorities[i]<priorities[j]) {
				int temp = priorities[i];
				//push(priorities);
				int pos = 1;
				while (pos < end) {
					priorities[pos - 1] = priorities[pos];
					pos++;
				}
				priorities[end - 1] = temp;
				if (location == 0)location = end-1;
				else location--;
				
				break;
			}
		}
		//큰값이 없는경우
		if (j == end) {
			if (location == 0)return answer;
			else {
				//push(priorities);
				int pos = 1;
				while (pos < priorities.size()) {
					priorities[pos - 1] = priorities[pos];
					pos++;
				}
				end--;
				location--;
				answer++;
				//i++;
			}
		}
	}
	return answer;
}

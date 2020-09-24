#include <string>
#include <vector>
#include <map>
#include<cstring>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
	vector<string>temp;
	vector<int>inout;
    map<string, string> user;
    
	for (int i = 0; i < record.size(); i++) {
		char state[8] = {0}, id[12] = {0}, nick[12] = {0};
		int n = 0, j = 0;
		while (1) {
			if (record[i][j] == ' ')break;
			state[n++] = record[i][j++];
		}
		n = 0;
		j++;
		while (1) {
			if (!strcmp(state, "Leave"))
                if(j == record[i].size()) break;
			if (record[i][j] == ' ')break;
			id[n++] = record[i][j++];
		}
		if (strcmp(state, "Leave")) {
			n = 0;
			j++;
			while (1) {
				if (j == record[i].size())break;
				nick[n++] = record[i][j++];
			}
		}
		if (!strcmp(state, "Enter")) {
			temp.push_back(id);
			inout.push_back(1);
			user[id] = nick;
		}
		else if (!strcmp(state, "Leave")) {
			temp.push_back(id);
			inout.push_back(2);
            user[id] = nick;
		}
		else {
			user[id] = nick;
		}
	}
	for (int i = 0; i < temp.size(); i++) {
		if (inout[i] == 1) 
			answer.push_back((user[temp[i]]) + "님이 들어왔습니다.");
		else 
			answer.push_back((user[temp[i]]) + "님이 나갔습니다.");
	}
	return answer;
}

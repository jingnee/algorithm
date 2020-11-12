#include <iostream>
#include <string>
#include <vector>

using namespace std;

int subTime(string start, string end) {
	int s_hour = stoi(start.substr(0, 2));
	int e_hour = stoi(end.substr(0, 2));
	int s_min = stoi(start.substr(3));
	int e_min = stoi(end.substr(3));
	if (s_hour != e_hour)e_min += (e_hour - s_hour) * 60;
	return e_min - s_min;
}

string solution(string m, vector<string> musicinfos) {
	string answer = "";
	int longest = 0;
	for (auto mu : musicinfos) {
		bool flag = false;
		string start_time = mu.substr(0, 5);
		string end_time = mu.substr(6, 5);
		int time = subTime(start_time, end_time);
		string music_name = "";
		string music_content = "";
		for (int i = 12; i < mu.size(); i++) {
			if (mu[i] == ',') {
				music_name = mu.substr(12, i - 12);
				music_content = mu.substr(i + 1);
				break;
			}
		}
		//치환
		string neo = "";
		for (int i = 0; i < m.size(); i++) {
			if (i < m.size() - 1) {
				if (m[i + 1] != '#')neo += m[i];
				else {
					if (m[i] == 'A')neo += 'a';
					else if (m[i] == 'C')neo += 'c';
					else if (m[i] == 'D')neo += 'd';
					else if (m[i] == 'F')neo += 'f';
					else if (m[i] == 'G')neo += 'g';
					i++;
				}
			}
			else neo += m[i];
		}
		string song = "";
		string full_song = "";
		for (int i = 0; i < music_content.size(); i++) {
			if (i < music_content.size() - 1) {
				if (music_content[i + 1] != '#')song += music_content[i];
				else {
					if (music_content[i] == 'A')song += 'a';
					else if (music_content[i] == 'C')song += 'c';
					else if (music_content[i] == 'D')song += 'd';
					else if (music_content[i] == 'F')song += 'f';
					else if (music_content[i] == 'G')song += 'g';
					i++;
				}
			}
			else song += music_content[i];
		}
		int music_size = song.size();
		int rep_num = time%music_size;
		for (int j = 0; j < time / music_size; j++)full_song.append(song);
		full_song.append(song.substr(0, rep_num));

		//노래 비교
		int neo_size = neo.size();
		if (neo.size() > full_song.size())continue;
		for (int k = 0; k <= full_song.size() - neo.size(); k++) {
			if (neo == full_song.substr(k, neo_size)) {
				flag = true;
				break;
			}
		}
		if (flag) {
			if (longest < time) {
				answer = music_name;
				longest = time;
			}
		}
	}
	if (answer.size() == 0)answer = "(None)";
	return answer;
}

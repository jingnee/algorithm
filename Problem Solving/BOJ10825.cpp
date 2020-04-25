/*국영수*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
struct Student {
	string name;
	int kor;
	int eng;
	int mat;
};
vector<Student> stu;

bool compare(Student &a, Student &b) {
	if (a.kor == b.kor) {
		if (a.eng == b.eng) {
			if (a.mat == b.mat) 
				return a.name < b.name;
			return a.mat > b.mat;
		}
		return a.eng < b.eng;
	}
	return a.kor > b.kor;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string name;
		int kor, eng, mat;
		cin >> name >> kor >> eng >> mat;
		stu.push_back({ name,kor,eng,mat });
	}

	sort(stu.begin(), stu.end(), compare);

	for (auto s : stu) {
		cout << s.name << "\n";
	}
	
}

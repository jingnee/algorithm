//Summer/Winter Coding(2019) 멀쩡한 사각형
using namespace std;

long long solution(int w, int h) {
	long long answer = (long long)w* (long long)h;
	int gcd = 0;
	for (int i = (w < h) ? w : h; i > 0; i--) {
		if ((w%i == 0) && (h%i == 0)) {
			gcd = i;
			break;
		}
	}
	answer -= gcd*((w / gcd) + (h / gcd) - 1);
	return answer;
}

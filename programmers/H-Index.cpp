#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end());
    for(int i=citations.size()-1;i>=0;i--){
        if(answer >= citations[i]) break;
        answer++;
    }
    return answer;
}

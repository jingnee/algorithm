#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end());
    int last=people.size()-1;
    int fir=0;
    for(int i=last;i>=fir;i--){
        int lim=limit;
        lim-=people[i];
        if(lim >= people[fir])fir++;
        answer++;
    }
    return answer;
}

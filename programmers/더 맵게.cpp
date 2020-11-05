#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> que;
    for(auto s:scoville)que.push(-s);
    
    while(1){
       int first = 0;
        int second = 0;
        if(!que.empty())first=-que.top();
        else{
            answer=-1;
            break;
        }
        que.pop();
        
        if(!que.empty())second=-que.top();
        else if(first<K && que.empty()){
            answer=-1;
            break;
        }
        que.pop();
        
        if(first>=K)break;
        int new_sco=first+second*2;
        que.push(-new_sco);
        answer++;
    }
    return answer;
}

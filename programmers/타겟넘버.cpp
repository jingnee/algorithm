//[programmers] 타겟 넘버
#include <string>
#include <vector>

using namespace std;
int oper[2]={1,-1};
int answer;

void DFS(int cnt, int target, int tot, int N, vector<int> numbers){
    if(cnt==N){
        if(tot==target)answer++;
        return;
    }
    for(int i=0;i<2;i++){
        DFS(cnt+1,target,tot+numbers[cnt]*oper[i],N,numbers);
    }
}
    
int solution(vector<int> numbers, int target) {
    DFS(0,target,0,numbers.size(),numbers);
    return answer;
}

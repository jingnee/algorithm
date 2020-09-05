// 문제가 개편되었습니다. 이로 인해 함수 구성이나 테스트케이스가 변경되어, 과거의 코드는 동작하지 않을 수 있습니다.
// 새로운 함수 구성을 적용하려면 [코드 초기화] 버튼을 누르세요. 단, [코드 초기화] 버튼을 누르면 작성 중인 코드는 사라집니다.
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int i = 0, d = 1;
    
    while(i<progresses.size()){
        int count=0;
        int t=progresses[i]+d*speeds[i];
        while(t <100){
            d++;
            t+=speeds[i];
        }
        count++;
        i++;
        while(i<progresses.size()){
        int temp=progresses[i]+d*speeds[i];
        if(temp >= 100) {count++; i++;}
            else break;
        }
       answer.push_back(count);
        //count=0;
    }
    
    return answer;
}

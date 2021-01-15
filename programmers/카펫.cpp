//[programmers] 真
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int tot = brown+yellow;
    for(int i=2;i<tot/2;i++){
        if(tot%i != 0)continue;
        int w=0, h=0;   //真, 真
        //真 真
        if(i>=tot/i){
            w=i;
            h=tot/i;
        }
        else{
            w=tot/i;
            h=i;
        }
        
        if(w*2+h*2-4 == brown){
            answer.push_back(w);
            answer.push_back(h);
            break;
        }
    }
    return answer;
}

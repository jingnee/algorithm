#include <string>
#include <map>
#include <vector>

using namespace std;

map<string,int> m;

int solution(vector<vector<string>> clothes) {
    int answer=1;
    for(auto clothe : clothes){
        if(m.count(clothe[1])==0)m.insert({clothe[1],1});
        m[clothe[1]]++;
    }
    for(auto a:m){
        answer *= a.second;
    }
    
    return answer-1;
}

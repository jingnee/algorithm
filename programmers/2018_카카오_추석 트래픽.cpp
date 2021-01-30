#include <string>
#include <vector>

using namespace std;

int solution(vector<string> lines) {
    int ans = 0;
    
    vector<pair<int,int>> logs; //start, end time
    for(auto l : lines){
        int end_time=0, start_time=0;
        end_time += 3600000 * stoi(l.substr(11, 2));
        end_time += 60000 * stoi(l.substr(14, 2));
        end_time += (int)(1000 * stod(l.substr(17, 6)));
        string tmp = l.substr(24);
        tmp.pop_back();
        start_time = end_time - (int)(1000 * stod(tmp)) + 1;
        
        logs.push_back(make_pair(start_time,end_time));
    }
    
    for(int i=0;i<logs.size();i++){
        int cnt=0;
        //i번째가 끝난 시점이랑 그 뒤에 애들 시작시점이 1초 이내인지 비교
        for(int j=i;j<logs.size();j++){
            if(logs[j].second - logs[i].second >= 4000) break;
            else if(logs[i].second+999 >= logs[j].first)cnt++;
        }
        ans = (ans<cnt)?cnt:ans;
    }
    return ans;
}

#include <string>
#include <set>
#include <vector>

using namespace std;
set<int> s;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int i=0;i<numbers.size()-1;i++){
        for(int j=i+1;j<numbers.size();j++){
            s.insert(numbers[i]+numbers[j]);
        }
    }
    for(auto a : s)answer.push_back(a);
    return answer;
}

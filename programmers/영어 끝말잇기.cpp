#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
   int i;
    int flag = 0;
    for(i=1;i<words.size();i++){
        char first = words[i].front();
        char last = words[i-1].back();
        if(first==last){
            for(int j=0;j<i;j++){
                if(!words[i].compare(words[j])){
                    flag=1;
                    break;
                }
            }
        }
        if(first!=last || flag==1){
            answer.push_back(i%n+1);
            answer.push_back(i/n+1);
            break;
        }
    }

    if(answer.size()==0){
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}

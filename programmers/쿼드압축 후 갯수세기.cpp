#include <string>
#include <vector>

using namespace std;
vector<int> answer(2,0);
vector<vector<int>> map;

//arr벡터를 들고다니면 시간초과가 남
void quard_zip(int sr, int sc, int len){
    /*
    if(len==1){
        answer[arr[sr][sc]]++;
        return;
    }
    */
    bool flag=true;
    int num = map[sr][sc];
    for(int i=sr;i<sr+len;i++){
        for(int j=sc;j<sc+len;j++){
            if(map[i][j]!=num){
                flag=false;
                break;
            }
        }
    }
    if(flag){
        answer[num]++;
        return;
    }
    else{
        quard_zip(sr,sc,len/2);
        quard_zip(sr,sc+len/2,len/2);
        quard_zip(sr+len/2,sc,len/2);
        quard_zip(sr+len/2,sc+len/2,len/2);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    map=arr;
    quard_zip(0,0,arr.size());
    
    return answer;
}

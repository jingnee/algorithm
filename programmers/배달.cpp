#include <iostream>
#include <vector>
//#define INF 999999;
using namespace std;
int INF = 999999;
bool visit[51];
int cost[51];
int map[51][51];

int shortest(int N){
    int min=INF;
    int index;
    for (int i=1;i<=N;i++){
        if(cost[i]<min && !visit[i])
        {
            index=i;
            min=cost[i];
        }
    }
    return index;
}
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    //무한대 값으로 초기화
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++){
            if(i==j)map[i][j]=0;
            else map[i][j]=INF;  
        }
          
    for(int i=0;i<road.size();i++){
if((map[road[i][0]][road[i][1]]<road[i][2]) && (map[road[i][0]][road[i][1]] < INF))
    continue;
        map[road[i][0]][road[i][1]]=road[i][2];
        map[road[i][1]][road[i][0]]=road[i][2];
    }
    //정점 1에서 갈 수 있는 경로값 초기화
    for(int i=1;i<=N;i++)
        cost[i]=map[1][i];
    
    visit[1]=true;
    for(int i=0;i<N-1;i++){
        int current = shortest(N);
        visit[current]=true;
        for(int j=1;j<=N;j++){
            if(!visit[j]){
                if(cost[current] + map[current][j] < cost[j])
                    cost[j]=cost[current]+map[current][j];
            }
        }
    }

    for(int i=1;i<=N;i++){
        if(cost[i]<=K)answer++;
    }
    return answer;
}

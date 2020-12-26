#include <string>
#include <vector>
#define Pillar 0
#define Install 1
using namespace std;
int building[110][110][2];

bool isInstall(int x, int y, int a, int n){
    //기둥인 경우
    if(a==0){
        if(y==0)return true;
        if(y>0 && building[y-1][x][0])return true;
        if((x>0 && building[y][x-1][1]) || building[y][x][1])return true;
        else return false;
    }   
    //보인 경우
    else{
        if(building[y-1][x][0] || (x<n && building[y-1][x+1][0]))return true;
        if((x>0 && building[y][x-1][1]) && (x<n && building[y][x+1][1]))return true;
        else return false;
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    for(auto build : build_frame){
        int x = build[0];
        int y = build[1];
        int a = build[2];
        int b = build[3];
        if(a==Pillar){
            //기둥 설치인 경우
            if(b==Install){
                building[y][x][0]=1;
                if(!isInstall(x,y,a,n))building[y][x][0]=0;
            }
            //기둥 삭제인 경우
            else{
                building[y][x][0]=0;
                if(building[y+1][x][0]){
                    if(!isInstall(x,y+1,0,n)){
                        building[y][x][0]=1;
                        continue;
                    }
                }
                if(building[y+1][x-1][1]){
                    if(!isInstall(x-1,y+1,1,n)){
                        building[y][x][0]=1;
                        continue;
                    }
                }
                if(building[y+1][x][1]){
                    if(!isInstall(x,y+1,1,n)){
                        building[y][x][0]=1;
                        continue;
                    }
                }
        }
    }
        else{
            //보 설치인 경우
            if(b==Install){
                building[y][x][1]=1;
                if(!isInstall(x,y,a,n))building[y][x][1]=0;
            }
            //보 삭제인 경우
            else{
                building[y][x][1]=0;
                if(building[y][x-1][1]){
                    if(!isInstall(x-1,y,1,n)){
                        building[y][x][1]=1;
                        continue;
                    }
                }
                if(building[y][x+1][1]){
                    if(!isInstall(x+1,y,1,n)){
                        building[y][x][1]=1;
                        continue;
                    }
                }
                if(building[y][x][0]){
                    if(!isInstall(x,y,0,n)){
                        building[y][x][1]=1;
                        continue;
                    }
                }
                if(building[y][x+1][0]){
                    if(!isInstall(x+1,y,0,n)){
                        building[y][x][1]=1;
                        continue;
                    }
                }
            }
        }
    }
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(building[j][i][0])answer.push_back({i,j,0});
            if(building[j][i][1])answer.push_back({i,j,1});
        }
    }
    
    return answer;
}

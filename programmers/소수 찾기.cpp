#include <string>
#include <algorithm>
#include <vector>

using namespace std;
bool isNotPrime[10000000];
bool visit[10000000];
bool numcheck[8];
int answer;

void checkPrime(int ssize){
    int maxi=10;
    isNotPrime[0]=isNotPrime[1]=true;
    
    while(ssize--)maxi*=10;
    maxi=min(maxi,9999999);
    
    for(int i=2;i*i<=maxi;i++){
        if(!isNotPrime[i]){
            for(int j=i*i;j<=maxi;j+=i)isNotPrime[j]=true;
        }
    }
}

void DFS(int N, int cnt, string num, string numbers){
    if(cnt==N){
        int n=stoi(num);
        if(!visit[n] && !isNotPrime[n]) answer++;
        visit[n]=true;
        return;
    }
    for(int i=0;i<numbers.size();i++){
        if(numcheck[i])continue;
        numcheck[i]=true;
        DFS(N,cnt+1,num+numbers[i],numbers);
        numcheck[i]=false;
    }
}

int solution(string numbers) {
    checkPrime(numbers.size());
    for(int i=1;i<=numbers.size();i++)DFS(i,0,"",numbers);
    return answer;
}

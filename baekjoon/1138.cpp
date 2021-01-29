//한 줄로 서기
#include <iostream>
using namespace std;

int N;
int bigger[11];
int answer[11];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  cin>>N;
  for(int i=0;i<N;i++)cin>>bigger[i];
  for(int i=0;i<N;i++){
    int cnt=bigger[i];    
    for(int j=0;j<N;j++){
      if(answer[j]!=0)continue;
      if(cnt==0){
        answer[j]=i+1;
        break;
      }
      cnt--;
    }
  }
  for(int i=0;i<N;i++)cout<<answer[i]<<" ";
}

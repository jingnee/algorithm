//전깃줄
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, ans;
int pole[501];
int dp[501];
vector<int> vec;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin>>N;
  for(int i=0;i<N;i++)  {
    int s,e;
    cin>>s>>e;
    pole[s]=e;
  }
  for(int i=1;i<500;i++){
    if(pole[i]!=0){
      vec.push_back(pole[i]);
    }
  }

  for(int i=0;i<vec.size();i++){
    int here = 0;
    for(int j=0;j<i;j++){
      if(vec[i]>=vec[j])
        here = max(here,dp[j]);
    }
    dp[i]=here+1;
    ans = max(ans,dp[i]);
  }
  cout<<N-ans;
}
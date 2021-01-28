//¿¿¿ ¿¿
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, answer;
vector<int> port;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>n;
  port.push_back(-10);
  for(int i=0;i<n;i++){
    int a;
    cin>>a;

    if(port.back()<a){
      port.push_back(a);
      answer++;
    }
    else{
      auto it = lower_bound(port.begin(),port.end(),a);
      *it = a;
    }
  }
  cout<<answer;
}
